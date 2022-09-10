#ifndef CTRLLINECHART_H
#define CTRLLINECHART_H

#include "ctrl.h"
#include "view/linechart.h"
#include "model/modellinechart.h"

class ctrlLineChart: public Ctrl
{
    Q_OBJECT
public:
    /**
     * @brief ctrlAreaChart costruttore del controller per la finestra line chart
     * @param v view
     * @param m model
     * @param parent controler padre
     */
    explicit ctrlLineChart(lineChart* v,modelLineChart* m, Ctrl* parent = nullptr);

    /**
     * @brief getView metodo virtuale che restituisce il campo view castato
     * al tipo corrente linechart
     * @return view
     */
    lineChart* getView() const override;

    /**
     * @brief getModel metodo virtuale che restituisce il campo model castato
     * al tipo corrente modellinechart
     * @return
     */
    modelLineChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLLINECHART_H
