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
    double costoVendita;
    unsigned int pezziVenduti;
    QDate data;

public:
    explicit dati(QString n,QString t, double tu, double ctm, double cb, double cl);

    //getter
    const QString& getNomeModello() const;
    const QString& getTessuto() const;
    double getTessUsato() const;
    double getCostoTessutoMq() const;
    double getCostoBase() const;
    double getCostoLavaggio() const;
    double getCostoFinale() const;
    double getCostoVendita() const;
    unsigned int getPezziVenduto() const;
    const QDate& getData() const;
    //setter
    void setNomeModello(const QString& n) {nomeModello=n;}
    void setTessuto(const QString& t) {tessuto=t;}
    void setTessutoUsato(const double tu) {tessUsato=tu;}
    void setCostoTessutoMq(const double ctm) {costoTessutoMq=ctm;}
    void setCostoLavaggio(const double cn) {costoLavaggio=cn;}
    void setCostoVendita(const double cv){costoVendita=cv;}
    void setPezziVenduti(const unsigned int pv){pezziVenduti=pv;}
    void setData(const QDate& d){data=d;}
};

#endif // DATI_H
