#include "tempchartform.h"
#include "ui_tempchartform.h"

#include<QtCharts>
#include<QChartView>
#include<QLineSeries>

tempChartForm::tempChartForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tempChartForm)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(nameDatabase);
    if (!m_db.open()) {
        qDebug() << "Error opening database";
        return;
    }
    QLineSeries *series = new QSplineSeries();
    QSqlQuery query("SELECT TIME, TEMP FROM TEMP ORDER BY TIME");
    while (query.next())
    {
        QDateTime xValue = QDateTime::fromString(query.value(0).toString(), "hh:mm:ss");
        qreal yValue = query.value(1).toDouble();
        series->append(xValue.toMSecsSinceEpoch(), yValue);
    }

    QChartView *chartView = new QChartView;
    chartView->chart()->addSeries(series);
    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setFormat("dd-MM-yyyy h:mm");
    chartView->chart()->setAxisX(axisX, series);

    QValueAxis *axisY = new QValueAxis;
    chartView->chart()->setAxisY(axisY, series);
    chartView->chart()->setTitle("Temperature Line Chart");
    chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame1);

    //QSqlTableModel *model = new QSqlTableModel(this, m_db);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT TEMP, TIME FROM TEMP", m_db);
    // model->setTable("TEMP"); // Change to your table name
    // model->select();
    ui->tableView->setModel(model);
    m_db.close();
    m_db.removeDatabase(QSqlDatabase::defaultConnection);
}

tempChartForm::~tempChartForm()
{
    // Close the database connection when the widget is destroyed
    m_db.close();
    delete ui;
}
