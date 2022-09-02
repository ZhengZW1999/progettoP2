#ifndef TABELLE_H
#define TABELLE_H

#include "model/model.h"
#include "model/datiModelli.h"
#include "model/dativendite.h"

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
    explicit tabelle(QString* path, QJsonDocument* file);

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

    const QJsonDocument& saveToQJSonDocument() const;

    void setPercosoFile(const QString& nomeF){*percorsoFile=nomeF;};
    const QString& getPercorsoFile() const;

};
#endif // TABELLE_H
