#include "modelPiechart.h"

pieChart::pieChart(tabelle *t)
{
    std::list<double> composizione;
        for(datiModelli* d : t->getListaDatiModelli()){
            composizione.clear();
            composizione.push_back(d->getCostoBase());
            composizione.push_back(d->getCostoLavaggio());
            composizione.push_back(d->getCostoTessutoMq()*d->getTessUsato());
            compCostoModello.insert({d->getNomeModello(),composizione});
        }
}

std::map<QString, std::list<double> > pieChart::getCompCostoModello() const{return compCostoModello;}
