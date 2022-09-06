#ifndef AREACHART_H
#define AREACHART_H

#include "view/view.h"

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QHBoxLayout>
#include <QBarCategoryAxis>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

class areaChart: public View
{
    Q_OBJECT
private:
    QChart* chart;
    QLineSeries *vendita = new QLineSeries();
    QLineSeries *produzione = new QLineSeries();
    QLineSeries *series = 0;
    QAreaSeries *prod;
    QAreaSeries *vend;
public:
    explicit areaChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertProdVend(const unsigned int n,const unsigned int p,const unsigned int v);

    void applyAreaAxis(const QStringList& mesi);

    void applyAreaChart();

};

#endif // AREACHART_H
