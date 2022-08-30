#include "modelPiechart.h"

pieChart::pieChart(tabelle *t)
{
    std::list<double> composizione;
        for(dati* d : t->getListaDati()){
            composizione.clear();
            composizione.push_back(d->getCostoBase());
            composizione.push_back(d->getCostoLavaggio());
            composizione.push_back(d->getCostoTessutoMq()*d->getTessUsato());
            composizione.push_back(d->getCostoVendita()-d->getCostoFinale());
            compCostoModello.insert({d->getNomeModello(),composizione});
        }
}

std::map<QString, std::list<double> > pieChart::getCompCostoModello() const{return compCostoModello;}
