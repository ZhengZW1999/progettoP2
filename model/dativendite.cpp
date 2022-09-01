#include "dativendite.h"

datiVendite::datiVendite(unsigned int pp, unsigned int pv, QDate ds):pezziProdotti(pp), pezziVenduti(pv), data(ds){}

unsigned int datiVendite::getPezziProdotti() const{return pezziProdotti;}

unsigned int datiVendite::getPezziVenduti() const{return pezziVenduti;}

const QDate &datiVendite::getData() const{return data;}
