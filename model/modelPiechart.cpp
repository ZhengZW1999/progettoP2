#include "modelPiechart.h"

modelPieChart::modelPieChart(tabelle *t)
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

        setCostiConsiderati();
}

std::map<std::pair<QString,QString>, std::list<float> > modelPieChart::getCompCostoModello() const{return compCostoModello;}

void modelPieChart::setCostiConsiderati()
{
    costiConsiderati.push_back("Costo Base");
    costiConsiderati.push_back("Costo Lavaggio");
    costiConsiderati.push_back("Costo Tessuto Usato");
}

const QStringList &modelPieChart::getCostiConsiderati() const{return costiConsiderati;}
