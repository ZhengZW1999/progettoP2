#include "modelstackedbarchart.h"

modelStackedBarChart::modelStackedBarChart(tabelle *t)
{
    for(const QString& modelli : *t->getListaModelli()){
        std::pair<float, float> rapporto(0.0,0.0);
        for(datiModelli* d : t->getListaDatiModelli()){
           if(d->getNomeModello() == modelli){
               rapporto.first += d->getCostoVendita();
               rapporto.second += d->getCostoFinale();
           }
        }
        rappSpesaGuadagno.insert({modelli,rapporto});
    }
}

std::map<QString, std::pair<float, float> > modelStackedBarChart::getRappSpesaGuadagno() const{return rappSpesaGuadagno;}
