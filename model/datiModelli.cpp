#include "datiModelli.h"

datiModelli::datiModelli(QString n, QString t, float tu, float ctm, float cb, float cl,float cv, unsigned int pg):
    nomeModello(n), tessuto(t), tessUsato(tu), costoTessutoMq(ctm), costoBase(cb), costoLavaggio(cl), costoVendita(cv), produzioneGiornaliera(pg) {}

const QString& datiModelli::getNomeModello() const{return nomeModello;}

const QString& datiModelli::getTessuto() const{return tessuto;}

float datiModelli::getTessUsato() const{return tessUsato;}

float datiModelli::getCostoTessutoMq() const{return costoTessutoMq;}

float datiModelli::getCostoBase() const{return costoBase;}

float datiModelli::getCostoLavaggio() const{return costoLavaggio;}

float datiModelli::getCostoFinale() const{return tessUsato*costoTessutoMq+costoBase+costoLavaggio;}

float datiModelli::getCostoVendita() const{return costoVendita;}

unsigned int datiModelli::getProduzioneGiornaliera() const{return produzioneGiornaliera;}



