#include "ctrllinechart.h"

ctrlLineChart::ctrlLineChart(lineChart *v, modelLineChart *m, Ctrl *parent): Ctrl(v,m,parent)
{
    unsigned int tessutiN = 1;
    QStringList tessuti;
    //do un input conv valori 0 per ogni m
    for(const auto &m : getModel()->getMod()){
        getView()->insertMaterialData(0,m,0);
    }
    for(const auto& n : getModel()->getProdModelliPerTess()){
        for(const auto& m : n.second){
            getView()->insertMaterialData(tessutiN,m.first,m.second);
        }
        tessuti.push_back(n.first);
        tessutiN++;
    }

    getView()->applyLineAxis(tessuti,getModel()->getMax());


}

lineChart *ctrlLineChart::getView() const{return static_cast<lineChart*>(vista);}

modelLineChart *ctrlLineChart::getModel() const{return static_cast<modelLineChart*>(modello);}

void ctrlLineChart::onViewClosed() const{delete this;}
