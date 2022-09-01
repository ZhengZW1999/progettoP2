#include "datiModelli.h"

datiModelli::datiModelli(QString n, QString t, double tu, double ctm, double cb, double cl,double cv, unsigned int pg):
    nomeModello(n), tessuto(t), tessUsato(tu), costoTessutoMq(ctm), costoBase(cb), costoLavaggio(cl), costoVendita(cv), produzioneGiornaliera(pg) {}

const QString& datiModelli::getNomeModello() const{return nomeModello;}

const QString& datiModelli::getTessuto() const{return tessuto;}

double datiModelli::getTessUsato() const{return tessUsato;}

double datiModelli::getCostoTessutoMq() const{return costoTessutoMq;}

double datiModelli::getCostoBase() const{return costoBase;}

double datiModelli::getCostoLavaggio() const{return costoLavaggio;}

double datiModelli::getCostoFinale() const{return tessUsato*costoTessutoMq+costoBase+costoLavaggio;}

double datiModelli::getCostoVendita() const{return costoVendita;}

unsigned int datiModelli::getProduzioneGiornaliera() const{return produzioneGiornaliera;}



