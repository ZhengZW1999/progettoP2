#ifndef CTRLPIECHART_H
#define CTRLPIECHART_H

#include "ctrl.h"
#include "view/piechart.h"
#include "model/modelPiechart.h"

class ctrlPieChart: public Ctrl
{
    Q_OBJECT
public:
    /**
     * @brief ctrlAreaChart costruttore del controller per la finestra pie chart
     * @param v view
     * @param m model
     * @param parent controler padre
     */
    explicit ctrlPieChart(pieChart* v,modelPieChart* m, Ctrl* parent = nullptr);

    /**
     * @brief getView metodo virtuale che restituisce il campo view castato
     * al tipo corrente piechart
     * @return view
     */
    pieChart* getView() const override;

    /**
     * @brief getModel metodo virtuale che restituisce il campo model castato
     * al tipo corrente modelPiechart
     * @return
     */
    modelPieChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLPIECHART_H
