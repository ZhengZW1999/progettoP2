#ifndef DATI_H
#define DATI_H

#include <QString>
#include <QDate>

class dati
{
private:
    QString nomeModello;
    QString tessuto;
    double tessUsato;
    double costoTessutoMq;
    double costoBase;
    double costoLavaggio;

public:
    explicit dati(QString n,QString t, double tu, double ctm, double cb, double cl);

    //getter
    const QString getNomeModello() const;
    const QString getTessuto() const;
    double getTessUsato() const;
    double getCostoTessutoMq() const;
    double getCostoBase() const;
    double getCostoLavaggio() const;
    //setter
    void setNomeModello(QString n) {nomeModello=n;}
    void setTessuto(QString t) {tessuto=t;}
    void setTessutoUsato(double tu) {tessUsato=tu;}
    void setCostoTessutoMq(double ctm) {costoTessutoMq=ctm;}
    void setCostoLavaggio(double cn) {costoLavaggio=cn;}
};

#endif // DATI_H
