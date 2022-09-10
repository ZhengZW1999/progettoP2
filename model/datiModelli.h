#ifndef DATIMODELLI_H
#define DATIMODELLI_H

#include <QString>
#include <QDate>
/**
 * @brief La classe datiModelli è un Modello relativa alla fase di pianificazione
 * Rapresenta il singolo record della tabella dei modelli,
 * rappresenta un singolo indumento e le sue caratteristiche
 */
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
    /**
     * @brief datiModelli Costruttore
     * @param n nome del modello
     * @param t tessuto usato per il modello
     * @param tu quantita' di tessuto usato in metri quadri
     * @param ctm costo del tessuto per metro quadro
     * @param cb costo base
     * @param cl costo lavaggio
     * @param cv perzzo di vendita
     * @param pg produzione giornaliera del modello
     */
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
    void setCostoBase(const double cb) {costoBase=cb;}
    void setCostoLavaggio(const double cn) {costoLavaggio=cn;}
    void setCostoVendita(const double cv){costoVendita=cv;}
    void setProduzioneGiornaliera(const unsigned int pg){produzioneGiornaliera=pg;}

};

#endif // DATIMODELLI_H
