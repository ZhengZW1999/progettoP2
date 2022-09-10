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

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    /**
     * @brief areaChart costruttore
     * @param size size della finestra
     * @param parent view che invoca il costruttore
     */
    explicit areaChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    /**
     * @brief insertProdVend metodo che inserisce i dati nella area chart
     * @param n dato x della QLineSeries vendita e produzione
     * @param p dato y della QLineSeries produzione
     * @param v dato y della QLineSeries vendita
     */
    void insertProdVend(const unsigned int n,const unsigned int p,const unsigned int v);

    /**
     * @brief applyAreaAxis metodo che setta le assi del grafico
     * @param mesi lista di stringhe con i mesi per asse X
     * @param max valore massimo che ci sara' nel grafico per asse Y
     */
    void applyAreaAxis(const QStringList& mesi, const unsigned int max);

    /**
     * @brief applyAreaChart metodo che setta le caratteristiche del grafico
     * come il colore, bordo, spessore
     * e lo aggiunge alla chart
     */
    void applyAreaChart();

};

#endif // AREACHART_H
