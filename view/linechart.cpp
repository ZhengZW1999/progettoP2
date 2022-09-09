#include "linechart.h"

lineChart::lineChart(const QSize &size, View *parent):View(size,parent), chart(new QChart())
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTitle("Produzione Giornaliera di ogni Modello per Tessuti diversi");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeDark);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);

    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);

    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(size);
}

void lineChart::insertMaterialData(const unsigned int n, const QString &modello, const unsigned int prodGiornaliera)
{
    if(serieModello.find(modello) == serieModello.end()){
        QLineSeries* ls = new QLineSeries();
        ls->append(n,prodGiornaliera);
        ls->setName(modello);
        serieModello.insert({modello,ls});
    }
    serieModello[modello]->append(n,prodGiornaliera);

    //ordino la serie
    /*
    QVector<QPointF> points = serieModello[modello]->pointsVector();
    std::sort(points.begin(), points.end(), [](const QPointF & p1, const QPointF & p2) {
        return p1.x() < p2.x();
    });
    serieModello[modello]->replace(points);*/
}

void lineChart::applyLineAxis(const QStringList &tessuti, const unsigned int max)
{
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append("0");
    axisX->append(tessuti);
    axisX->setRange(QString("0"),tessuti.last());
    chart->setAxisX(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,max);
    chart->addAxis(axisY, Qt::AlignLeft);


    chart->removeAllSeries();
    for (const auto& sm : serieModello) {
        chart->addSeries(sm.second);
        sm.second->attachAxis(axisX);
        sm.second->attachAxis(axisY);
    }
    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Tessuto");
       chart->axisY()->setTitleText("Produzione giornaliera");
    }
}
