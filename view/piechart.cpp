#include "piechart.h"

pieChart::pieChart(const QSize &s, view *parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    chart->addSeries(series);
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
    resize(s);
}

void pieChart::insertDati(const QString &tipoCosto, float costo)
{
    series->append(tipoCosto, costo);
}

void pieChart::viewSetting()
{
    for(QPieSlice* slice : series->slices()){
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setLabelColor(Qt::green);
    }
    chart->setTitle("Costo finale per produzione");
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
}
