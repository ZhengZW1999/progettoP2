#include "areachart.h"

areaChart::areaChart(const QSize &size, View *parent): View(size,parent), chart(new QChart()), prod(new QAreaSeries), vend(new QAreaSeries)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setAnimationDuration(1500);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle("Rapporto Produzione Vendite per ogni Mese");

    QChartView* chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(size);
}

void areaChart::insertProdVend(const unsigned int n,const unsigned int p, const unsigned int v)
{
    *vendita <<QPoint(n,v);
    *produzione <<QPoint(n,p);
}

void areaChart::applyAreaAxis(const QStringList &mesi, const unsigned int max)
{
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("0");
    axisX->append(mesi);

    axisX->setRange("0",mesi.last());
    chart->addAxis(axisX, Qt::AlignBottom);
    vend->attachAxis(axisX);
    prod->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,max);
    chart->addAxis(axisY, Qt::AlignLeft);
    vend->attachAxis(axisY);
    prod->attachAxis(axisY);

    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Anno Mese");
       chart->axisY()->setTitleText("Produzione e Vendita");
    }
}

void areaChart::applyAreaChart()
{
    prod->setUpperSeries(produzione);
    prod->setLowerSeries(vendita);
    prod->setName("Produzione");

    vend->setUpperSeries(vendita);
    vend->setLowerSeries(series);
    vend->setName("Vendita");

    QPen penProd(Qt::yellow);
    penProd.setWidth(3);
    prod->setPen(penProd);

    QPen penVend(Qt::red);
    penVend.setWidth(3);
    vend->setPen(penVend);

    QLinearGradient gradientProd(QPointF(0, 0), QPointF(0, 1));
    gradientProd.setColorAt(0.0, Qt::yellow);
    gradientProd.setColorAt(1.0, Qt::yellow);
    gradientProd.setCoordinateMode(QGradient::ObjectBoundingMode);
    prod->setBrush(gradientProd);

    QLinearGradient gradientVend(QPointF(0, 0), QPointF(0, 1));
    gradientVend.setColorAt(0.0, Qt::transparent);
    gradientVend.setColorAt(1.0, Qt::red);
    gradientVend.setCoordinateMode(QGradient::ObjectBoundingMode);
    vend->setBrush(gradientVend);

    chart->removeAllSeries();
    chart->addSeries(prod);
    chart->addSeries(vend);
}
