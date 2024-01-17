#include "preschartform.h"
#include "ui_preschartform.h"

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

presChartForm::presChartForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::presChartForm)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(nameDatabase);
    if (!m_db.open()) {
        qDebug() << "Error opening database";
        return;
    }
    QLineSeries *series = new QSplineSeries();
    QSqlQuery query("SELECT TIME, PRES FROM PRESSURE ORDER BY TIME");
    while (query.next())
    {
        QDateTime xValue = QDateTime::fromString(query.value(0).toString(), "hh:mm:ss");
        qreal yValue = query.value(1).toDouble();
        series->append(xValue.toMSecsSinceEpoch(), yValue);
    }




    // QChart *chart = new QChart();
    // chart->addSeries(series);
    // chart->createDefaultAxes();

    // chart->setAnimationOptions(QChart::AnimationOption::SeriesAnimations);
    // chart->setTheme(QChart::ChartTheme::ChartThemeDark);

    // chart->legend()->hide();
    // //chart->legend()->setAlignment(Qt::AlignmentFlag::AlignBottom);

    // QChartView *chartview = new QChartView(chart);
    QChartView *chartView = new QChartView;
    chartView->chart()->addSeries(series);
    // ...
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd-MM-yyyy h:mm");
    chartView->chart()->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis;
    chartView->chart()->setAxisY(axisY, series);
    chartView->chart()->setTitle("Line Chart Example");
    chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame1);

    //QSqlTableModel *model = new QSqlTableModel(this, m_db);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT PRES, TIME FROM PRESSURE", m_db);
    // model->setTable("PRESSURE"); // Change to your table name
    // model->select();
    ui->tableView->setModel(model);
    m_db.close();
    m_db.removeDatabase(QSqlDatabase::defaultConnection);

}

presChartForm::~presChartForm()
{
    m_db.close();
    delete ui;
}
