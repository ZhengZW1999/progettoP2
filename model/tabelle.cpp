#include "tabelle.h"

tabelle::tabelle()
{
    listaTessuti = new QStringList();
    listaModelli = new QStringList();
    percorsoFile = new QString();
}

tabelle::tabelle(QString *path, QJsonDocument *file)
{
    listaModelli = JSONFilePicker::getMaterialList(file);
    listaTessuti = JSONFilePicker::getMaterialList(file);
    listaDatiModelli = JSONFilePicker::getRecords(file);
    listaDatiVendite = JSONFilePicker::getRecords(file);
    percorsoFile = path;
}

tabelle::~tabelle()
{
    delete percorsoFile;
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

const QJsonDocument &tabelle::saveToQJSonDocument() const
{
    QJsonDocument* modelJson = new QJsonDocument();
    QJsonObject main;

    QJsonArray arrayModelli;
    for(datiModelli* r : listaDatiModelli){
        QJsonObject oggetto;
        oggetto.insert(QString::fromStdString("Nome Modello"),r->getNomeModello());
        oggetto.insert(QString::fromStdString("Tessuto"),r->getTessuto()));
        oggetto.insert(QString::fromStdString("Tessuto Usato"),QJsonValue((float)r->getTessUsato()));
        oggetto.insert(QString::fromStdString("Costo Tessuto Per Metro Quadro"),QJsonValue((float)r->getCostoTessutoMq()));
        oggetto.insert(QString::fromStdString("Costo Base"),QJsonValue((float)r->getCostoBase()));
        oggetto.insert(QString::fromStdString("Costo Lavaggio"),QJsonValue((float)r->getCostoLavaggio()));
        oggetto.insert(QString::fromStdString("Prezo Vendita"),QJsonValue((float)r->getCostoVendita()));
        oggetto.insert(QString::fromStdString("Produzione Giornaliera"),QJsonValue((int)r->getProduzioneGiornaliera()));
        arrayModelli.push_back(oggetto);
    }
    QJsonArray arrayVendite;
    for(datiVendite* d : listaDatiVendite){
        QJsonObject oggetto;
        oggetto.insert(QString::fromStdString("Pezzi Prodotti"),d->getPezziProdotti());
        oggetto.insert(QString::fromStdString("Pezzi Venduti"),d->getPezziVenduti());
        oggetto.insert(QString::fromStdString("Mese"),d->getData().toString("MMMM/yyyy"));
        arrayVendite.push_back(oggetto);
    }
    main.insert(QString::fromStdString("Modelli"),QJsonArray::fromStringList(*listaModelli));
    main.insert(QString::fromStdString("Tessuti"),QJsonArray::fromStringList(*listaTessuti));
    main.insert(QString::fromStdString("Dati dei modelli"),arrayModelli);
    main.insert(QString::fromStdString("Dati delle vendite"),arrayVendite);
    modelJson->setObject(main);

    return *modelJson;
}

const QString &tabelle::getPercorsoFile() const{return *percorsoFile;}

