#include "tabelle.h"

tabelle::tabelle()
{
    listaTessuti = new QStringList();
    listaModelli = new QStringList();
    filepath = new QString();
}

tabelle::~tabelle()
{
    delete filepath;
    delete listaModelli;
    delete listaTessuti;
    for(auto dm : listaDatiModelli) delete dm;
    for(auto dv : listaDatiVendite) delete dv;
}

QStringList *tabelle::getListaTessuti() const{return listaTessuti;}
QStringList *tabelle::getListaModelli() const{return listaModelli;}
std::list<datiModelli *> tabelle::getListaDatiModelli() const{return listaDatiModelli;}
std::list<datiVendite *> tabelle::getListaDatiVendite() const{return listaDatiVendite;}

void tabelle::aggiungiRigaModelli(datiModelli *dm){listaDatiModelli.push_back(dm);}
void tabelle::rimuoviRigaModelli(unsigned int riga)
{
    std::list<datiModelli *>::iterator it= listaDatiModelli.begin();
    std::advance(it,riga);
    listaDatiModelli.erase(it);
}

void tabelle::aggiungiRigaVendite(datiVendite *dv){listaDatiVendite.push_back(dv);}
void tabelle::rimuoviRigaVendite(unsigned int riga)
{
    std::list<datiVendite *>::iterator it= listaDatiVendite.begin();
    std::advance(it,riga);
    listaDatiVendite.erase(it);
}

void tabelle::aggiungiModello(const QString &m){listaModelli->push_back(m);}
void tabelle::rimuoviModello(unsigned int riga){listaModelli->removeAt(riga);}

void tabelle::aggiungiTessuto(const QString &t){listaTessuti->push_back(t);}
void tabelle::rimuoviTessuto(unsigned int riga){listaTessuti->removeAt(riga);}

