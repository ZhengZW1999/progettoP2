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

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    /**
     * @brief lineChart costruttore
     * @param size size della finestra
     * @param parent view che invoca il costruttore
     */
    explicit lineChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    /**
     * @brief insertMaterialData metodo che inserisce i dati per line chart
     * @param n dato X della QLineSeries
     * @param modello il nome del QLineSeries
     * @param prodGiornaliera dato Y della QLineSeries
     */
    void insertMaterialData(const unsigned int n,const QString& modello, const unsigned int prodGiornaliera);

    /**
     * @brief applyLineAxis metodo che setta le assi del grafico e applica la chart
     * @param tessuti lista di tessuti da mettere nell'asse X
     * @param max valore massimo che verra' rappresentata nell'asse Y
     */
    void applyLineAxis(const QStringList& tessuti,const unsigned int max);
};

#endif // LINECHART_H
