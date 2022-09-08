#include "ctrlstackedbarchart.h"

ctrlStackedBarChart::ctrlStackedBarChart(stackedBarChart *v, modelStackedBarChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    QStringList modelli;
    for(const auto& n : getModel()->getRappSpesaGuadagno()){
        getView()->insertSetCosto(n.second);
        modelli.push_back(n.first);
    }
    getView()->applyStackedChart();

    getView()->applyStackedBarAxis(modelli);


}


stackedBarChart *ctrlStackedBarChart::getView() const{return static_cast<stackedBarChart*>(vista);}

modelStackedBarChart *ctrlStackedBarChart::getModel() const{return static_cast<modelStackedBarChart*>(modello);}

void ctrlStackedBarChart::onViewClosed() const{delete this;}
