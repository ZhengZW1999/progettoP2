#ifndef PIECHART_H
#define PIECHART_H

#include "view.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QHBoxLayout>
#include <QComboBox>
#include <QStringList>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

class pieChart: public View
{
private:
    QPieSeries *series;
    QChart *chart;

    /**
     * @brief connectViewSignals Metodo virtuale che serve a collegare i segnali dei singoli
     * Widget ai segnali della View
     */
    void connectViewSignals() const override{
        // non ci sono segnali da connettere
    }

public:
    /**
     * @brief pieChart costruttore
     * @param s size della finestra
     * @param parent view che invoca il costruttoe
     */
    explicit pieChart(const QSize& s = QSize(800,500),View* parent = nullptr);

    /**
     * @brief insertDati metodo che inserisce i dati per pie chart
     * @param tessuto il nome del dato
     * @param quantita il valore del dato
     */
    void insertDati(const QString& tessuto, unsigned int quantita);

    /**
     * @brief viewSetting applica le caratteristiche della chart
     */
    void viewSetting();
};

#endif // PIECHART_H
