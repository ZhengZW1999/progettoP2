#ifndef CTRLAREACHART_H
#define CTRLAREACHART_H

#include "ctrl.h"
#include "view/areachart.h"
#include "model/modelareaChart.h"
#include <qdebug.h>

class ctrlAreaChart: public Ctrl
{
    Q_OBJECT
public:
    /**
     * @brief ctrlAreaChart costruttore del controller per la finestra area chart
     * @param v view
     * @param m model
     * @param parent controler padre
     */
    explicit ctrlAreaChart(areaChart* v,modelAreaChart* m, Ctrl* parent = nullptr);

    /**
     * @brief getView metodo virtuale che restituisce il campo view castato
     * al tipo corrente areachart
     * @return view
     */
    areaChart* getView() const override;

    /**
     * @brief getModel metodo virtuale che restituisce il campo model castato
     * al tipo corrente modelareaChart
     * @return
     */
    modelAreaChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLAREACHART_H
