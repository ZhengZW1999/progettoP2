#ifndef TABELLE_H
#define TABELLE_H

#include "model/model.h"
#include "model/datiModelli.h"
#include "model/dativendite.h"

#include "control/gestionefilejson.h"

#include <QString>
#include <list>
#include <QJsonDocument>

/**
 * @brief tabelle la Classe Che si occupa di rappresentare i dati che servono alla schermata tableview, in particolare
 * Elabora i Dati presi da un file JSON, e li memorizza dandogli un significato.
 */
class tabelle: public model
{
private:
    QString* percorsoFile;
    QStringList* listaTessuti;
    QStringList* listaModelli;
    std::list<datiModelli*> listaDatiModelli;
    std::list<datiVendite*> listaDatiVendite;
public:

    /**
     * @brief tabelle Costruttore che viene usato per creare un modello vuoto, senza dati
     */
    explicit tabelle();

    /**
     * @brief AdminModel Costruttore che viene usato per creare un modello a partire da un Documento Json
     * @param data dati in formato Json
     */
    explicit tabelle(QString* path, QJsonDocument* file, bool b);

    /**
     * @brief tabelle Costruttore di copia profondo
     * @param t modello da copiare
     */
    explicit tabelle(const tabelle& t);

    /**
      * Distruttore virtuale ridefinito in quanto deve ocuparsi anche
      * di distruggere i campi in modo profondo
      */
    ~tabelle() override;

    /**
     * @brief getListaTessuti metodo getter
     * @return lista dei tessuti QStringList
     */
    QStringList* getListaTessuti() const;

    /**
     * @brief getListaModelli metodo getter
     * @return lista dei modelli QStringList
     */
    QStringList* getListaModelli() const;

    /**
     * @brief getListaDatiModelli metodo getter
     * @return lista dei dati datiModelli
     */
    std::list<datiModelli*> getListaDatiModelli() const;

    /**
     * @brief getListaDatiVendite metodo getter
     * @return lista dei dati datiVendite
     */
    std::list<datiVendite*> getListaDatiVendite() const;

    /**
     * @brief aggiungiRigaModelli Metodo che dato un ptr datiModelli lo aggiunge alla lista di datiModelli*
     * @param dm datiModelli* da aggiungere
     */
    void aggiungiRigaModelli(datiModelli* dm);

    /**
     * @brief rimuoviRigaModelli Metodo che dato un intero rimuove dalla lista di datiModelli l'elemento row-esimo
     * @param row indice dell'elemento da rimuovere
     */
    void rimuoviRigaModelli(unsigned int riga);

    /**
     * @brief aggiungiRigaVendite Metodo che dato un ptr datiVendite lo aggiunge alla lista di datiVendite*
     * @param dv datiVendite* da aggiungere
     */
    void aggiungiRigaVendite(datiVendite* dv);

    /**
     * @brief rimuoviRigaVendite Metodo che dato un intero rimuove dalla lista di datiVendite l'elemento row-esimo
     * @param row indice dell'elemento da rimuovere
     */
    void rimuoviRigaVendite(unsigned int riga);

    /**
     * @brief aggiungiModello Aggiunge alla QStringList listaModelli un modello Qstring m
     * @param m Modello da agigungere
     */
    void aggiungiModello(const QString& m);

    /**
     * @brief rimuoviModello Rimuove un modello dalla listaModelli alla riga==indice riga
     * @param riga indice del modello da rimuovere
     */
    void rimuoviModello(unsigned int riga);

    /**
     * @brief aggiungiTessuto Aggiunge alla QStringList listaTessuti un modello Qstring t
     * @param t Tessuto da agigungere
     */
    void aggiungiTessuto(const QString& t);

    /**
     * @brief rimuoviTessuto Rimuove un tessuto dalla listaTessuti alla riga==indice riga
     * @param riga indice del tessuto da rimuovere
     */
    void rimuoviTessuto(unsigned int riga);

    /**
     * @brief getDatiModelli Metodo getter che restituisce un record specifico dalla list datiModelli
     * @param riga indice del datiModelli dalla std::list da restituire
     * @return datiModelli da restituire
     */
    datiModelli* getDatiModelli(unsigned int riga);

    /**
     * @brief getDatiVendite Metodo getter che restituisce un record specifico dalla list datiVendite
     * @param riga indice del datiVendite dalla std::list da restituire
     * @return datiVendite da restituire
     */
    datiVendite* getDatiVendite(unsigned int riga);

    /**
     * @brief setModello Metodo che modifica un modello eistente nella listaModelli e lo sostituisce con modello
     * @param riga indice del modello da sostituire
     * @param modello Modello con cui sostituire
     */
    void setModello(unsigned int riga, const QString& modello);

    /**
     * @brief setTessuto Metodo che modifica un modello eistente nella listaTessuti e lo sostituisce con tessuto
     * @param riga indice del tessuto da sostituire
     * @param tessuto Tessuto con cui sostituire
     */
    void setTessuto(unsigned int riga, const QString& tessuto);

    /**
     * @brief getModello Metodo che ritorna un modello specifico dalla listaModelli
     * @param riga riga del materiale , indice del materiale da ritornare
     * @return modello da ritornare
     */
    const QString& getModello(unsigned int riga)const;

    /**
     * @brief getTessuto Metodo che ritorna un tessuto specifico dalla listaTessuti
     * @param riga riga del tessuto , indice del tessuto da ritornare
     * @return tessuto da ritornare
     */
    const QString& getTessuto(unsigned int riga)const;

    /**
     * @brief modelSaveToQJSonDocument Metodo che trasforma la classe tabelle in un QJsonDocument,
     * viene tralasciata l'informazione della path
     * @return JSON document con i dati del modello
     */
    const QJsonDocument& modelSaveToQJSonDocument() const;

    /**
     * @brief venditeSaveToQJSonDocument Metodo che trasforma la classe tabelle in un QJsonDocument,
     * viene tralasciata l'informazione della path
     * @return JSON document con i dati delle vendite
     */
    const QJsonDocument& venditeSaveToQJSonDocument() const;

    /**
     * @brief setPercosoFile Metodo che imposta la path del modello
     * @param nomeF
     */
    void setPercosoFile(const QString& nomeF);

    /**
     * @brief getPercorsoFile Ritorna la path del file, contente il suo percorso ed il nome del file
     * @return percorsoFile
     */
    const QString& getPercorsoFile() const;

};
#endif // TABELLE_H
