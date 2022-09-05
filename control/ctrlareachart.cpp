#include "ctrlareachart.h"


ctrlAreaChart::ctrlAreaChart(areaChart *v, modelAreaChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    unsigned int mese = 0;
    unsigned int produzione = 0;
    unsigned int vendita = 0;
    QStringList tuttiMesi;
    for(const auto& n : getModel()->getRappProdVend()){
        produzione = n.second.first;
        vendita = n.second.second;
        getView()->insertProdVend(mese,produzione,vendita);
        tuttiMesi.push_back(n.first);
        mese++;
    }

    getView()->applyAreaAxis(tuttiMesi);

    getView()->applyAreaChart();
}

areaChart *ctrlAreaChart::getView() const{return static_cast<areaChart*>(vista);}

modelAreaChart *ctrlAreaChart::getModel() const{return static_cast<modelAreaChart*>(modello);}

void ctrlAreaChart::onViewClosed() const{delete this;}
