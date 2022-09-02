#ifndef DATIMODELLI_H
#define DATIMODELLI_H

#include <QString>
#include <QDate>

class datiModelli
{
private:
    QString nomeModello;
    QString tessuto;
    float tessUsato;
    float costoTessutoMq;
    float costoBase;
    float costoLavaggio;
    float costoVendita;
    unsigned int produzioneGiornaliera;
public:
    explicit datiModelli(QString n,QString t, float tu, float ctm, float cb, float cl,float cv, unsigned int pg);

    //getter
    const QString& getNomeModello() const;
    const QString& getTessuto() const;
    float getTessUsato() const;
    float getCostoTessutoMq() const;
    float getCostoBase() const;
    float getCostoLavaggio() const;
    float getCostoFinale() const;
    float getCostoVendita() const;
    unsigned int getProduzioneGiornaliera() const;

    //setter
    void setNomeModello(const QString& n) {nomeModello=n;}
    void setTessuto(const QString& t) {tessuto=t;}
    void setTessutoUsato(const float tu) {tessUsato=tu;}
    void setCostoTessutoMq(const float ctm) {costoTessutoMq=ctm;}
    void setCostoLavaggio(const float cn) {costoLavaggio=cn;}
    void setCostoVendita(const float cv){costoVendita=cv;}
    void setProduzioneGiornaliera(const unsigned int pg){produzioneGiornaliera=pg;}

};

#endif // DATIMODELLI_H
