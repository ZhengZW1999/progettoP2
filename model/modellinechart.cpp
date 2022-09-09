#include "modellinechart.h"

modelLineChart::modelLineChart(tabelle *t)
{
    mod.clear();
    for(const QString& modello : *t->getListaModelli())
        mod << modello;
    max = 0;
    for(const QString& tessuto : *t->getListaTessuti()){
        std::map<QString, unsigned int> prodGiornaliera;
        for(datiModelli* d : t->getListaDatiModelli()){
            if(d->getTessuto() == tessuto)
                prodGiornaliera[d->getNomeModello()] += d->getProduzioneGiornaliera();
            if(max < d->getProduzioneGiornaliera() || max < prodGiornaliera[d->getNomeModello()])
                max = d->getProduzioneGiornaliera() < prodGiornaliera[d->getNomeModello()] ? prodGiornaliera[d->getNomeModello()] :d->getProduzioneGiornaliera();

        }
        prodModelliPerTess.insert({tessuto,prodGiornaliera});
    }
}

std::map<QString, std::map<QString, unsigned int> > modelLineChart::getProdModelliPerTess() const{return prodModelliPerTess;}

const QStringList modelLineChart::getMod() const{return mod;}

const unsigned int modelLineChart::getMax() const{return max;}
