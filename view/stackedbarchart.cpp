#include "stackedbarchart.h"

stackedBarChart::stackedBarChart(const QSize &s, View *parent):View(s,parent), chart(new QChart()), series(new QStackedBarSeries())
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Prezzo Vendita / Prezzo Produzione Complessivi");

    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(s);
}

void stackedBarChart::insertSetCosto(std::pair<float, float> rappCosto)
{
    *guadagno << rappCosto.first;
    *cFinale << rappCosto.second;
}

void stackedBarChart::applyStackedBarAxis(const QStringList &modelli)
{
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(modelli);

    axisX->setRange(modelli.first(),modelli.last());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Modelli");
       chart->axisY()->setTitleText("Prezzo Vendita");
    }
}

void stackedBarChart::applyStackedChart()
{
    chart->removeAllSeries();
    series->append(guadagno);
    series->append(cFinale);
    chart->addSeries(series);
}
