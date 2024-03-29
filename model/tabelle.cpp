#include "tabelle.h"

tabelle::tabelle()
{
    listaTessuti = new QStringList();
    listaModelli = new QStringList();
    percorsoFile = new QString();
}

tabelle::tabelle(QString *path, QJsonDocument *file, bool b)
{
    if(b){
        listaDatiModelli = gestioneFileJSon::getDM(file);
        listaModelli = gestioneFileJSon::getModellList(file);
        listaTessuti = gestioneFileJSon::getTessutiList(file);

        percorsoFile = path;
    } else {
        listaDatiVendite = gestioneFileJSon::getDV(file);
        percorsoFile = path;
    }
}

tabelle::tabelle(const tabelle &t)
{
    percorsoFile = new QString(*t.percorsoFile);
    listaModelli = new QStringList(*t.listaModelli);
    listaTessuti = new QStringList(*t.listaTessuti);
    for(const auto& dm : t.listaDatiModelli)
        listaDatiModelli.push_back(new datiModelli(*dm));
    for(const auto& dv : t.listaDatiVendite)
        listaDatiVendite.push_back(new datiVendite(*dv));
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

datiModelli *tabelle::getDatiModelli(unsigned int riga)
{
    std::list<datiModelli *>::iterator it= listaDatiModelli.begin();
    std::advance(it,riga);
    return *it;
}

datiVendite *tabelle::getDatiVendite(unsigned int riga)
{
    std::list<datiVendite *>::iterator it= listaDatiVendite.begin();
    std::advance(it,riga);
    return *it;
}

void tabelle::setModello(unsigned int riga, const QString &modello){listaModelli->replace(riga,modello);}
void tabelle::setTessuto(unsigned int riga, const QString &tessuto){listaTessuti->replace(riga,tessuto);}

const QString &tabelle::getModello(unsigned int riga) const{return listaModelli->at(riga);}
const QString &tabelle::getTessuto(unsigned int riga) const{return listaTessuti->at(riga);}

const QJsonDocument &tabelle::modelSaveToQJSonDocument() const
{
    QJsonDocument* modelJson = new QJsonDocument();
    QJsonObject main;

    QJsonArray arrayModelli;
    for(datiModelli* dm : listaDatiModelli){
        QJsonObject oggetto;
        oggetto.insert(QString::fromStdString("Nome Modello"),dm->getNomeModello());
        oggetto.insert(QString::fromStdString("Tessuto"),dm->getTessuto());
        oggetto.insert(QString::fromStdString("Tessuto Usato"),QJsonValue((double)dm->getTessUsato()));
        oggetto.insert(QString::fromStdString("Costo Tessuto Per Metro Quadro"),QJsonValue((double)dm->getCostoTessutoMq()));
        oggetto.insert(QString::fromStdString("Costo Base"),QJsonValue((double)dm->getCostoBase()));
        oggetto.insert(QString::fromStdString("Costo Lavaggio"),QJsonValue((double)dm->getCostoLavaggio()));
        oggetto.insert(QString::fromStdString("Prezo Vendita"),QJsonValue((double)dm->getCostoVendita()));
        oggetto.insert(QString::fromStdString("Produzione Giornaliera"),QJsonValue((int)dm->getProduzioneGiornaliera()));
        arrayModelli.push_back(oggetto);
    }
    main.insert(QString::fromStdString("Modelli"),QJsonArray::fromStringList(*listaModelli));
    main.insert(QString::fromStdString("Tessuti"),QJsonArray::fromStringList(*listaTessuti));
    main.insert(QString::fromStdString("Dati dei modelli"),arrayModelli);
    modelJson->setObject(main);

    return *modelJson;
}

const QJsonDocument &tabelle::venditeSaveToQJSonDocument() const
{
    QJsonDocument* modelJson = new QJsonDocument();
    QJsonObject main;

    QJsonArray arrayVendite;
    for(datiVendite* d : listaDatiVendite){
        QJsonObject oggetto;
        oggetto.insert(QString::fromStdString("Pezzi Prodotti"),QJsonValue((int)d->getPezziProdotti()));
        oggetto.insert(QString::fromStdString("Pezzi Venduti"),QJsonValue((int)d->getPezziVenduti()));
        oggetto.insert(QString::fromStdString("Mese"),d->getData().toString("dd/MM/yyyy"));
        arrayVendite.push_back(oggetto);
    }
    main.insert(QString::fromStdString("Dati delle vendite"),arrayVendite);
    modelJson->setObject(main);

    return *modelJson;
}

const QString &tabelle::getPercorsoFile() const{return *percorsoFile;}

void tabelle::setPercosoFile(const QString& nomeF){
    *percorsoFile = nomeF;
}

