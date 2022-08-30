#ifndef TABELLE_H
#define TABELLE_H

#include "model/model.h"
#include "model/dati.h"

#include <QString>
#include <list>
#include <QJsonDocument>

class tabelle: public model
{
private:
    QString* filepath;
    QStringList* listaTessuti;
    QStringList* listaModelli;
    std::list<dati*> listaDati;
public:
    explicit tabelle();
    explicit tabelle(QString* path, QJsonDocument* file);

    ~tabelle() override;

    QStringList* getListaTessuti() const;
    QStringList* getListaModelli() const;
    std::list<dati*> getListaDati() const;

    void aggiungiRiga(dati* d);
    void rimuoviRiga(unsigned int riga);

    void aggiungiModello(const QString& m);
    void rimuoviModello(unsigned int riga);

    void aggiungiTessuto(const QString& t);
    void rimuoviTessuto(unsigned int riga);
};
#endif // TABELLE_H
