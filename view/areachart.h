#ifndef AREACHART_H
#define AREACHART_H

#include "view/view.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

QT_CHARTS_USE_NAMESPACE

class areaChart: public View
{
    Q_OBJECT
private:
    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    static QLineSeries *series;
public:
    explicit areaChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertProdVend(const unsigned int p,const unsigned int v);

    void applyAreaAxis(const QStringList& mesi);

    void applyAreaChart();

};

#endif // AREACHART_H
