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

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }
public:
    /**
     * @brief barChart costruttore
     * @param size size della finestra
     * @param parent view che invoca la funzione
     */
    explicit barChart(const QSize& size = QSize(800,500), View* parent = nullptr);

    /**
     * @brief insertSetTessuto metodo che inserisce i dati che servono al bar chart
     * @param costi lista di float che rappresentano i costi
     */
    void insertSetTessuto(std::list<float> costi);

    /**
     * @brief createBarChartSet crea i barset
     * @param tipiC lista di nomi dei costi per creare i barset
     */
    void createBarChartSet(const QStringList& tipiC);

    /**
     * @brief applyBarAxis metodo per settare le assi con una lista modelli
     * @param modelli lista di stringhe che serve per costruitr l'asse X
     */
    void applyBarAxis(const QStringList& modelli);

    /**
     * @brief applySetsOnChart metodo che costruisce effettivamente la chart
     */
    void applySetsOnChart();
};

#endif // BARCHART_H
