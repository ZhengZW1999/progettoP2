#include "barchart.h"

barChart::barChart(const QSize &size, View *parent): View(size,parent), chart(new QChart()), series(new QBarSeries())
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Composizione del costo finale");

    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(size);
}

void barChart::insertSetTessuto(std::list<double> costi)
{
    int n= 0;
    for(auto m : costi){
        *tipiCosti[n] << m;
        n++;
    }
}

void barChart::createBarChartSet(const QStringList &tipiC)
{
    for(const auto& n : tipiC){
        QBarSet* set = new QBarSet(n);
        tipiCosti.push_back(set);
    }
}

void barChart::applyBarAxis(const QStringList &modelli)
{
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(modelli);
    chart->createDefaultAxes();
    chart->setAxisX(axisX, series);

    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Modelli");
       chart->axisY()->setTitleText("Costi");
    }
}

void barChart::applySetsOnChart()
{
    for(auto n : tipiCosti) series->append(n);

    chart->addSeries(series);

}
