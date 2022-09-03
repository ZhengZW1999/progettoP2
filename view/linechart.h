#ifndef LINECHART_H
#define LINECHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QHBoxLayout>

#include "view/view.h"

QT_CHARTS_USE_NAMESPACE

class lineChart: public View
{
    Q_OBJECT
private:
    QChart* chart;
    std::map<QString,QLineSeries> serieModello;
public:
    explicit lineChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertMaterialData(const QString& tessuto,const QString& modello, const uint prodGiornaliera);
};

#endif // LINECHART_H
