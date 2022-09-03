#include "modellinechart.h"


modelLineChart::modelLineChart(tabelle *t)
{
    for(const QString& tessuto : *t->getListaTessuti()){
        std::map<QString, unsigned int> prodGiornaliera;
        for(datiModelli* d : t->getListaDatiModelli()){
            if(d->getTessuto() == tessuto)
                prodGiornaliera[d->getNomeModello()] += d->getProduzioneGiornaliera();
        }
        prodModelliPerTess.insert({tessuto,prodGiornaliera});
    }
}

std::map<QString, std::map<QString, unsigned int> > modelLineChart::getProdModelliPerTess() const{return prodModelliPerTess;}
