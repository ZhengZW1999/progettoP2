#ifndef CTRLSTACKEDBARCHART_H
#define CTRLSTACKEDBARCHART_H

#include "ctrl.h"
#include "view/stackedbarchart.h"
#include "model/modelstackedbarchart.h"

class ctrlStackedBarChart: public Ctrl
{
    Q_OBJECT
public:
    explicit ctrlStackedBarChart(stackedBarChart* v,modelStackedBarChart* m, Ctrl* parent = nullptr);

    stackedBarChart* getView() const override;

    modelStackedBarChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLSTACKEDBARCHART_H
