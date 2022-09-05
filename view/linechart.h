#ifndef LINECHART_H
#define LINECHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QHBoxLayout>
#include <map>
#include <QBarCategoryAxis>
#include <QValueAxis>

#include "view/view.h"

QT_CHARTS_USE_NAMESPACE

class lineChart: public View
{
    Q_OBJECT
private:
    QChart* chart;
    QLineSeries* ls;
    std::map<QString,QLineSeries*> serieModello;
public:
    explicit lineChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertMaterialData(const unsigned int n,const QString& modello, const uint prodGiornaliera);

    void applyPieAxis(const QStringList& tessuti);

    void applyChartSeries();
};

#endif // LINECHART_H
