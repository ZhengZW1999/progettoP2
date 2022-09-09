#include "ctrlareachart.h"


ctrlAreaChart::ctrlAreaChart(areaChart *v, modelAreaChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    unsigned int mese = 1;
    QStringList tuttiMesi;
    getView()->insertProdVend(0,0,0);
    for(const auto& n : getModel()->getRappProdVend()){
        getView()->insertProdVend(mese,n.second.first,n.second.second);

        tuttiMesi.push_back(n.first);
        mese++;
    }
    getView()->applyAreaChart();

    getView()->applyAreaAxis(tuttiMesi,getModel()->getMax());

}

areaChart *ctrlAreaChart::getView() const{return static_cast<areaChart*>(vista);}

modelAreaChart *ctrlAreaChart::getModel() const{return static_cast<modelAreaChart*>(modello);}

void ctrlAreaChart::onViewClosed() const{delete this;}
