#ifndef CTRLBARCHART_H
#define CTRLBARCHART_H

#include "ctrl.h"
#include "view/barchart.h"
#include "model/modelbarchart.h"

class ctrlBarChart: public Ctrl
{
    Q_OBJECT
public:
    /**
     * @brief ctrlAreaChart costruttore del controller per la finestra bar chart
     * @param v view
     * @param m model
     * @param parent controler padre
     */
    explicit ctrlBarChart(barChart* v,modelBarChart* m, Ctrl* parent = nullptr);

    /**
     * @brief getView metodo virtuale che restituisce il campo view castato
     * al tipo corrente barchart
     * @return view
     */
    barChart* getView() const override;

    /**
     * @brief getModel metodo virtuale che restituisce il campo model castato
     * al tipo corrente modelbarchart
     * @return
     */
    modelBarChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLBARCHART_H
