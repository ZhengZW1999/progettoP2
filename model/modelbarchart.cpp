#include "modelbarchart.h"

modelBarChart::modelBarChart(tabelle *t)
{
    std::list<double> composizione;
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

        setCostiConsiderati();
}

std::map<std::pair<QString,QString>, std::list<double> > modelBarChart::getCompCostoModello() const{return compCostoModello;}

void modelBarChart::setCostiConsiderati()
{
    costiConsiderati.push_back("Costo Base");
    costiConsiderati.push_back("Costo Lavaggio");
    costiConsiderati.push_back("Costo Tessuto Usato");
}

const QStringList &modelBarChart::getCostiConsiderati() const{return costiConsiderati;}
