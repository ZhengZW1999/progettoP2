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

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    /**
     * @brief stackedBarChart costruttore
     * @param size size della finestra
     * @param parent view che invoca il costruttore
     */
    explicit stackedBarChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    /**
     * @brief insertSetCosto metodo che inserisce i dati per bar chart sovrapposto
     * @param rappCosto coppia di dati che rappresentano i pezzi prodotti/venduti
     */
    void insertSetCosto(std::pair<double,double> rappCosto);

    /**
     * @brief applyStackedBarAxis metodo che costruisce e setta le assi X e Y
     * @param modelli dato da mettere nell'asse X
     */
    void applyStackedBarAxis(const QStringList& modelli);

    /**
     * @brief applyStackedChart metodo che applica la chart
     */
    void applyStackedChart();
};

#endif // STACKEDBARCHART_H
