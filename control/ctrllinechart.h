#ifndef CTRLLINECHART_H
#define CTRLLINECHART_H

#include "ctrl.h"
#include "view/linechart.h"
#include "model/modellinechart.h"

class ctrlLineChart: public Ctrl
{
    Q_OBJECT
public:
    explicit ctrlLineChart(lineChart* v,modelLineChart* m, Ctrl* parent = nullptr);

    lineChart* getView() const override;

    modelLineChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLLINECHART_H
