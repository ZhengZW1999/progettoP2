#include "dati.h"

dati::dati(QString n, QString t, double tu, double ctm, double cb, double cl):
    nomeModello(n), tessuto(t), tessUsato(tu), costoTessutoMq(ctm), costoBase(cb), costoLavaggio(cl) {}

const QString& dati::getNomeModello() const{return nomeModello;}

const QString& dati::getTessuto() const{return tessuto;}

double dati::getTessUsato() const{return tessUsato;}

double dati::getCostoTessutoMq() const{return costoTessutoMq;}

double dati::getCostoBase() const{return costoBase;}

double dati::getCostoLavaggio() const{return costoLavaggio;}

double dati::getCostoFinale() const{return tessUsato*costoTessutoMq+costoBase+costoLavaggio;}

double dati::getCostoVendita() const{return costoVendita;}

unsigned int dati::getPezziProdotti() const{return getPezziProdotti();}

unsigned int dati::getPezziVenduti() const{return pezziVenduti;}

const QDate &dati::getData() const{return data;}

