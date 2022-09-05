#ifndef CTRLPIECHART_H
#define CTRLPIECHART_H

#include "ctrl.h"
#include "view/piechart.h"
#include "model/modelPiechart.h"

class ctrlPieChart: public Ctrl
{
    Q_OBJECT
public:
    explicit ctrlPieChart(pieChart* v,modelPieChart* m, Ctrl* parent = nullptr);

    pieChart* getView() const override;

    modelPieChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLPIECHART_H
