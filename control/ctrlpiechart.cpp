#include "ctrlpiechart.h"

ctrlPieChart::ctrlPieChart(pieChart *v, modelPieChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    QStringList modelloTessuto;
    for(const auto& n : getModel()->getCompCostoModello()){
        unsigned int pos = 0;
        for(const auto& m : n.second){
            getView()->insertDati(getModel()->getCostiConsiderati().at(pos),m);
            pos++;
        }
        modelloTessuto.push_back(n.first.first+"-"+n.first.second);
    }

    getView()->createChartListBox(&modelloTessuto);

    getView()->viewSetting();
}


pieChart *ctrlPieChart::getView() const{return static_cast<pieChart*>(vista);}

modelPieChart *ctrlPieChart::getModel() const{return static_cast<modelPieChart*>(modello);}

void ctrlPieChart::onViewClosed() const{delete this;}
