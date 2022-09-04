#include "linechart.h"

lineChart::lineChart(const QSize &size, View *parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;

    chart->setTitle("Rapporto Durata Consumo");
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

void lineChart::insertMaterialData(const unsigned int n, const QString &modello, const uint prodGiornaliera)
{
    if(serieModello.find(modello) == serieModello.end()){
        ls->append(n,prodGiornaliera);
        ls->setName(modello);
        serieModello.insert({modello,ls});
    }
    serieModello[modello]->append(n,prodGiornaliera);

    //ordino la serie
    QVector<QPointF> points = serieModello[modello]->pointsVector();
    std::sort(points.begin(), points.end(), [](const QPointF & p1, const QPointF & p2) {
        return p1.x() < p2.x();
    });
    serieModello[modello]->replace(points);
}

void lineChart::applyPieAxis(const QStringList &tessuti)
{
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(tessuti);
    //Set range per il grafico, massimo 6 mesi PER volta da mostrare
    //Se il numero di mesi disponibili è più grande di 6 imposto un range dal primo al 6 mese
    //Se il numero di mesi disponibile è più piccolo di 6 imposto un range dal primo al ultimo
    axisX->setRange(tessuti.first(),tessuti.last());
    chart->addAxis(axisX, Qt::AlignBottom);
    ls->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    ls->attachAxis(axisY);

    //Imposto titolo degli assi
    if(chart->axisX() && chart->axisY()){
       chart->axisX()->setTitleText("Tessuto");
       chart->axisY()->setTitleText("Produzione giornaliera per modello");
    }
}

void lineChart::applyChartSeries()
{
    chart->removeAllSeries();
    for (const auto& kv : serieModello) {
        chart->addSeries(kv.second);
    }
}
