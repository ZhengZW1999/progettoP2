#ifndef DATIMODELLI_H
#define DATIMODELLI_H

#include <QString>
#include <QDate>

class datiModelli
{
private:
    QString nomeModello;
    QString tessuto;
    double tessUsato;
    double costoTessutoMq;
    double costoBase;
    double costoLavaggio;
    double costoVendita;
    unsigned int produzioneGiornaliera;
public:
    explicit datiModelli(QString n,QString t, double tu, double ctm, double cb, double cl,double cv, unsigned int pg);

    //getter
    const QString& getNomeModello() const;
    const QString& getTessuto() const;
    double getTessUsato() const;
    double getCostoTessutoMq() const;
    double getCostoBase() const;
    double getCostoLavaggio() const;
    double getCostoFinale() const;
    double getCostoVendita() const;
    unsigned int getProduzioneGiornaliera() const;

    //setter
    void setNomeModello(const QString& n) {nomeModello=n;}
    void setTessuto(const QString& t) {tessuto=t;}
    void setTessutoUsato(const double tu) {tessUsato=tu;}
    void setCostoTessutoMq(const double ctm) {costoTessutoMq=ctm;}
    void setCostoLavaggio(const double cn) {costoLavaggio=cn;}
    void setCostoVendita(const double cv){costoVendita=cv;}
    void setProduzioneGiornaliera(const unsigned int po){produzioneGiornaliera=pg;}

};

#endif // DATIMODELLI_H
