#include "modellinechart.h"


void modelLineChart::setMod(const QString &s)
{
    if(!mod.contains(s)) mod.push_back(s);
}

modelLineChart::modelLineChart(tabelle *t)
{
    mod = *(t->getListaModelli());
    for(const QString& tessuto : *t->getListaTessuti()){
        std::map<QString, unsigned int> prodGiornaliera;
        for(datiModelli* d : t->getListaDatiModelli()){
            //setMod(d->getNomeModello());
            if(d->getTessuto() == tessuto)
                prodGiornaliera[d->getNomeModello()] += d->getProduzioneGiornaliera();

        }
        prodModelliPerTess.insert({tessuto,prodGiornaliera});
    }
}

std::map<QString, std::map<QString, unsigned int> > modelLineChart::getProdModelliPerTess() const{return prodModelliPerTess;}

const QStringList modelLineChart::getMod() const{
     return mod;
 }
