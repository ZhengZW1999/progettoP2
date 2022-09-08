#ifndef BARCHART_H
#define BARCHART_H

#include "view/view.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QHBoxLayout>

QT_CHARTS_USE_NAMESPACE

class barChart: public View
{
    Q_OBJECT
private:
    QChart* chart;
    QBarSeries *series;
    QList<QBarSet*> tipiCosti;
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    explicit barChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    void insertSetTessuto(std::list<float> costi);

    void createBarChartSet(const QStringList& tipiC);

    void applyBarAxis(const QStringList& modelli);

    void applySetsOnChart();
};

#endif // BARCHART_H
