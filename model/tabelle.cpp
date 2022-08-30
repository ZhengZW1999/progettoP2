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
    for(auto d : listaDati) delete d;
}

QStringList *tabelle::getListaTessuti() const{return listaTessuti;}
QStringList *tabelle::getListaModelli() const{return listaModelli;}
std::list<dati *> tabelle::getListaDati() const{return listaDati;}

void tabelle::aggiungiRiga(dati *d){listaDati.push_back(d);}
void tabelle::rimuoviRiga(unsigned int riga)
{
    std::list<dati *>::iterator it= listaDati.begin();
    std::advance(it,riga);
    listaDati.erase(it);
}

void tabelle::aggiungiModello(const QString &m){listaModelli->push_back(m);}
void tabelle::rimuoviModello(unsigned int riga){listaModelli->removeAt(riga);}

void tabelle::aggiungiTessuto(const QString &t){listaTessuti->push_back(t);}
void tabelle::rimuoviTessuto(unsigned int riga){listaTessuti->removeAt(riga);}

