#include "piechart.h"

pieChart::pieChart(const QSize &s, View *parent): View(s,parent), series(new QPieSeries()), chart(new QChart())
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(s);
}

void pieChart::insertDati(const QString &tessuto, unsigned int quantita)
{
    series->append(tessuto+tr(" N: ")+QString::number(quantita), quantita);
}

void pieChart::viewSetting()
{
    for(QPieSlice* slice : series->slices()){
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setLabelColor(Qt::green);
    }
    chart->setTitle("Numero Scelte del Tessuto");
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
}
