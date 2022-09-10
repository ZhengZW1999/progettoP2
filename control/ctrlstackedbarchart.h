#ifndef CTRLSTACKEDBARCHART_H
#define CTRLSTACKEDBARCHART_H

#include "ctrl.h"
#include "view/stackedbarchart.h"
#include "model/modelstackedbarchart.h"

class ctrlStackedBarChart: public Ctrl
{
    Q_OBJECT
public:
    /**
     * @brief ctrlAreaChart costruttore del controller per la finestra bat chart sovrapposto
     * @param v view
     * @param m model
     * @param parent controler padre
     */
    explicit ctrlStackedBarChart(stackedBarChart* v,modelStackedBarChart* m, Ctrl* parent = nullptr);

    /**
     * @brief getView metodo virtuale che restituisce il campo view castato
     * al tipo corrente stackedbarchart
     * @return view
     */
    stackedBarChart* getView() const override;

    /**
     * @brief getModel metodo virtuale che restituisce il campo model castato
     * al tipo corrente modelstackedbarchart
     * @return
     */
    modelStackedBarChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLSTACKEDBARCHART_H
