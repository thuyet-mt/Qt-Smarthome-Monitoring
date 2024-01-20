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
    QChartView *chartView = new QChartView;
    chartView->chart()->addSeries(series);
    // ...
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd-MM-yyyy h:mm");
    chartView->chart()->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis;
    chartView->chart()->setAxisY(axisY, series);
    chartView->chart()->setTitle("Pressure Line Chart");
    chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame1);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT PRES, TIME FROM PRESSURE", m_db);
    ui->tableView->setModel(model);
    m_db.close();
    m_db.removeDatabase(QSqlDatabase::defaultConnection);

}

presChartForm::~presChartForm()
{
    m_db.close();
    delete ui;
}
