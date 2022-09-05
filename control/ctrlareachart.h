#ifndef CTRLAREACHART_H
#define CTRLAREACHART_H

#include "ctrl.h"
#include "view/areachart.h"
#include "model/modelareaChart.h"

class ctrlAreaChart: public Ctrl
{
    Q_OBJECT
public:
    explicit ctrlAreaChart(areaChart* v,modelAreaChart* m, Ctrl* parent = nullptr);

    areaChart* getView() const override;

    modelAreaChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLAREACHART_H
