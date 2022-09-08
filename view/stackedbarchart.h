#ifndef STACKEDBARCHART_H
#define STACKEDBARCHART_H

#include "view/view.h"

#include <QHBoxLayout>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QStackedBarSeries>
#include <QValueAxis>

QT_CHARTS_USE_NAMESPACE

class stackedBarChart: public View
{
    Q_OBJECT
private:
    QChart* chart;
    QStackedBarSeries *series;
    QBarSet *cFinale= new QBarSet("Costo Produzione");;
    QBarSet *guadagno= new QBarSet("Guadagno");;

    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    explicit stackedBarChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertSetCosto(std::pair<float,float> rappCosto);

    void applyStackedBarAxis(const QStringList& modelli);

    void applyStackedChart();
};

#endif // STACKEDBARCHART_H
