#include "ctrlbarchart.h"

ctrlBarChart::ctrlBarChart(barChart *v, modelBarChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    QStringList modelli;
    getView()->createBarChartSet(getModel()->getCostiConsiderati());

    for(const auto& n : getModel()->getCompCostoModello()){
        modelli.push_back(n.first.first+tr("-")+n.first.second);
        getView()->insertSetTessuto(n.second);
    }

    getView()->applySetsOnChart();

    getView()->applyBarAxis(modelli);
}

barChart *ctrlBarChart::getView() const{return static_cast<barChart*>(vista);}

modelBarChart *ctrlBarChart::getModel() const{return static_cast<modelBarChart*>(modello);}

void ctrlBarChart::onViewClosed() const{delete this;}
