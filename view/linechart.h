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

    std::map<QString,QLineSeries*> serieModello;

    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    explicit lineChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertMaterialData(const unsigned int n,const QString& modello, const unsigned int prodGiornaliera);

    void applyLineAxis(const QStringList& tessuti,const unsigned int max);
};

#endif // LINECHART_H
