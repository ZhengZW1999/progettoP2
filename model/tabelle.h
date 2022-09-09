#ifndef TABELLE_H
#define TABELLE_H

#include "model/model.h"
#include "model/datiModelli.h"
#include "model/dativendite.h"

#include "control/gestionefilejson.h"

#include <QString>
#include <list>
#include <QJsonDocument>

class tabelle: public model
{
private:
    QString* percorsoFile;
    QStringList* listaTessuti;
    QStringList* listaModelli;
    std::list<datiModelli*> listaDatiModelli;
    std::list<datiVendite*> listaDatiVendite;
public:
    explicit tabelle();
    explicit tabelle(QString* path, QJsonDocument* file, bool b);

    ~tabelle() override;

    QStringList* getListaTessuti() const;
    QStringList* getListaModelli() const;
    std::list<datiModelli*> getListaDatiModelli() const;
    std::list<datiVendite*> getListaDatiVendite() const;

    void aggiungiRigaModelli(datiModelli* dm);
    void rimuoviRigaModelli(unsigned int riga);

    void aggiungiRigaVendite(datiVendite* dv);
    void rimuoviRigaVendite(unsigned int riga);

    void aggiungiModello(const QString& m);
    void rimuoviModello(unsigned int riga);

    void aggiungiTessuto(const QString& t);
    void rimuoviTessuto(unsigned int riga);

    datiModelli* getDatiModelli(unsigned int riga);
    datiVendite* getDatiVendite(unsigned int riga);

    void setModello(unsigned int riga, const QString& modello);
    void setTessuto(unsigned int riga, const QString& tessuto);

    const QString& getModello(unsigned int riga)const;
    const QString& getTessuto(unsigned int riga)const;

    const QJsonDocument& modelSaveToQJSonDocument() const;

    const QJsonDocument& venditeSaveToQJSonDocument() const;

    void setPercosoFile(const QString& nomeF);;
    const QString& getPercorsoFile() const;

};
#endif // TABELLE_H
