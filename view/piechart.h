#ifndef PIECHART_H
#define PIECHART_H

#include "view.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE

class pieChart: public view
{
private:
    QPieSeries *series;
    QChart *chart;
    QChartView *chartView;
public:
    explicit pieChart(const QSize& s = QSize(800,500),view* parent = nullptr);

    void insertDati(const QString& tipoCosto, float costo);

    void viewSetting();
};

#endif // PIECHART_H
