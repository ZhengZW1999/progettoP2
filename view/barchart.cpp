#include "barchart.h"

barChart::barChart(const QSize &size, View *parent): View(size,parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Numero Scelte del Tessuto");

    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(size);
}

void barChart::insertSetTessuto(const QString &tessuto, unsigned int n)
{
    QBarSet* set = new QBarSet(tessuto);
    *set << n;
    series->append(set);
}

void barChart::applySetsOnChart()
{
    chart->addSeries(series);
    chart->createDefaultAxes();
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Tessuto");
       chart->axisY()->setTitleText("Quantita'");
    }
}
