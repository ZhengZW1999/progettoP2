#include "ctrlpiechart.h"

ctrlPieChart::ctrlPieChart(pieChart *v, modelPieChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    for(const auto& n : getModel()->getTessUsatoModello()){
        getView()->insertDati(n.first,n.second);
    }

    getView()->viewSetting();
}


pieChart *ctrlPieChart::getView() const{return static_cast<pieChart*>(vista);}

modelPieChart *ctrlPieChart::getModel() const{return static_cast<modelPieChart*>(modello);}

void ctrlPieChart::onViewClosed() const{delete this;}
