#ifndef CTRLBARCHART_H
#define CTRLBARCHART_H

#include "ctrl.h"
#include "view/barchart.h"
#include "model/modelbarchart.h"

class ctrlBarChart: public Ctrl
{
    Q_OBJECT
public:
    explicit ctrlBarChart(barChart* v,modelBarChart* m, Ctrl* parent = nullptr);

    barChart* getView() const override;

    modelBarChart* getModel() const override;

public slots:
    /**
     * @brief onViewClosed Metodo virtuale che definisce il cosa fare alla chiusura della schermata
     * in questo caso NIENTE, distrugge solamente il costruttore
     */
    void onViewClosed() const override;
};

#endif // CTRLBARCHART_H
