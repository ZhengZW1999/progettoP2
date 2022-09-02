#include "modelPiechart.h"

pieChart::pieChart(tabelle *t)
{
    std::list<float> composizione;
        for(datiModelli* d : t->getListaDatiModelli()){
            std::pair<QString, QString> modelloTessuto("","");
            composizione.clear();
            composizione.push_back(d->getCostoBase());
            composizione.push_back(d->getCostoLavaggio());
            composizione.push_back(d->getCostoTessutoMq()*d->getTessUsato());
            modelloTessuto.first=d->getNomeModello();
            modelloTessuto.second=d->getTessuto();
            compCostoModello.insert({modelloTessuto,composizione});
        }
}

std::map<std::pair<QString,QString>, std::list<float> > pieChart::getCompCostoModello() const{return compCostoModello;}
