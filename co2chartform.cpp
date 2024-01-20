#include "co2chartform.h"
#include "ui_co2chartform.h"

co2ChartForm::co2ChartForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::co2ChartForm)
{
    ui->setupUi(this);
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(nameDatabase);
    if (!m_db.open()) {
        qDebug() << "Error opening database";
        return;
    }
    QLineSeries *series = new QSplineSeries();
    QSqlQuery query("SELECT GAS, TEMP FROM GAS ORDER BY TIME");
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
    chartView->chart()->setTitle("Gas Concentration Line Chart");
    chartView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setParent(ui->horizontalFrame1);

    //QSqlTableModel *model = new QSqlTableModel(this, m_db);
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT GAS, TIME FROM GAS", m_db);
    ui->tableView->setModel(model);
    m_db.close();
    m_db.removeDatabase(QSqlDatabase::defaultConnection);
}

co2ChartForm::~co2ChartForm()
{
    m_db.close();
    delete ui;
}
