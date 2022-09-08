#include "modelPiechart.h"

modelPieChart::modelPieChart(tabelle *t)
{
    for(const QString& tessuto : *t->getListaTessuti()){
        unsigned int n = 0;
        for(datiModelli* d : t->getListaDatiModelli()){
            if(d->getTessuto() == tessuto)
                n++;
        }
        tessUsatoModello.insert({tessuto,n});
    }
}

std::map<QString, unsigned int> modelPieChart::getTessUsatoModello() const{return tessUsatoModello;}
