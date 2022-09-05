#include "ctrlbarchart.h"

ctrlBarChart::ctrlBarChart(barChart *v, modelBarChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    for(const auto& n : getModel()->getTessUsatoModello()){
        getView()->insertSetTessuto(n.first,n.second);
    }

    getView()->applySetsOnChart();
}

barChart *ctrlBarChart::getView() const{return static_cast<barChart*>(vista);}

modelBarChart *ctrlBarChart::getModel() const{return static_cast<modelBarChart*>(modello);}

void ctrlBarChart::onViewClosed() const{delete this;}
