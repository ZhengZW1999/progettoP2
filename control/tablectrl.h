#ifndef TABLECTRL_H
#define TABLECTRL_H

#include "control/ctrl.h"

#include "view/tableview.h"

#include "model/tabelle.h"

#include <list>

class tableCtrl: public Ctrl
{
    Q_OBJECT
private:
    /**
     * @brief connectViewCtrlSignalsSlots Metodo overloading
     * Questo Metodo serve a connettere i SIGNAL della AdminView ai Slot del AdminCtrl
     */

    void connectViewCtrlSignalsSlots() const;

public:
    /**
     * @brief AdminCtrl
     * @param v View collegata al Controller
     * @param m Model collegato al Controller
     */
    tableCtrl(tableView* v, tabelle* m = new tabelle(), Ctrl* parent = nullptr);

    /**
     * @brief getView Ritorna La View castata almeno al tipo corrente AdminView
     * @return
     */
    tableView* getView() const override;

    /**
     * @brief getModel Ritorna il Model castato almeno al tipo corrente ModelView
     * @return
     */
    tabelle* getModel() const override;

signals:

public slots:
     /**
      * @brief onViewClosed SLOT eseguito alla ricezione di SEGNALI di chiusura della View
      * In questo caso distrugger il suddetto controller, che di seguito distrugge la view e il model
      */
     void onViewClosed() const override;
     /**
      * @brief onRecordTableRemoved SLOT eseguito alla ricezione di SEGNALI dalla view per la rimozione
      * di un record dalla record table, questo slot modifica il modello aggiornandolo con il record da rimuovere
      * @param row indice del record da rimuovere dalla recordList
      */
     void onDataTableRemoved(unsigned int row);

     /**
      * @brief onDataTableAdded SLOT eseguito alla ricezione di SEGNALI dalla view per l'aggiunta di una riga nella tabella Dati
      * viene quindi modificato il model aggiungendo un record alla dataList
      * @param m Modello
      * @param t Tessuto
      * @param tU Tessuto usato
      * @param cT Costo Tessuto per Mq
      * @param cB Costo Base
      * @param cL Costo Lavaggio
      * @param cV Costo Vendita
      */
     void onDataTableAdded(const QString& m, const QString& t, float tU, float cT, float cB, float cL, float cV, unsigned int pG);

     /**
      * @brief onDataTableModelloMod SLOT eseguito alla ricezione di SEGNALI dalla view
      * per la modifica del Modello di una specifico riga della tabella Dati
      * @param row indice della riga da modificare dalla dataList
      * @param m Modello
      */
     void onDataTableModelloMod(unsigned int row,const QString& m);

     /**
      * @brief onDataTableTessutoMod SLOT eseguito alla ricezione di SEGNALI dalla view
      * per la modifica del Tessuto di una specifico riga della tabella Dati
      * @param row indice della riga da modificare dalla dataList
      * @param t Tessuto
      */
     void onDataTableTessutoMod(unsigned int row,const QString& t);

     /**
      * @brief onMaterialTableAdded SLOT eseguito alla ricezione di SEGNALI dalla view per la
      * aggiunta di un materiale alla materialList
      * @param m Materiale
      */

     void onModelliTableAdded(const QString& m);

     /**
      * @brief onMaterialTableMaterialeMod SLOT eseguito alla ricezione di SEGNALI dalla view
      * per la modifica di un materiale specifico dalla materialList
      * Verifica che il materiale non esista già effettivamente nel modello per non creare duplicati.
      * Se trova un materiale già esistente la suddetta modifica
      * viene attuata con il carattere '_' appeso alla fine.
      * Successivamente si manda un segnale della VIEW per aggioranre i QComboBox
      * @param row indice del materiale da modificare dalla materialList
      * @param m Materiale
      */

     void onModelliTableModelloMod(unsigned int row,const QString& m);

     /**
      * @brief onMaterialTableRemoved SLOT eseguito alla ricezione di SEGNALI dalla view
      * per la rimozione di uno specifico materiale dalla materlList
      * Il materiale può essere rimosso solamente se non è presente in uno dei
      * record della recordList (Per una questione di integrità dei dati).
      * @param row indice del record da rimuovereturno
      * @param check questo parametro rapresenta se la rimozione del materiale è già stata verificata
      */

     void onModelliTableRemoved(unsigned int row);

     /**
      * @brief onNewBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * Azione da eseguire per aprire un nuovo progetto
      */

     //void onNewBPressed();

     /**
      * @brief onSaveBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * azione eseguite per salvare il progetto
      */

     //void onSaveBPressed()const;

     /**
      * @brief onSaveAsBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * azione eseguita per salvare il progetto con un nome diverso
      */

     //void onSaveAsBPressed()const;

     /**
      * @brief onHomeBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * azione eseguita per tornare alla home
      */

     //void onHomeBPressed();

     /**
      * @brief onPieChartBPressed SLOT eseguito alla ricezione di SEGNALI dall view
      * che chiede come azione eseguita l'apertura di un PieChart
      * viene usato il modello attuale nel Ctrl
      * @param detail
      */

     //void onPieChartBPressed(bool detail)const;

     /**
      * @brief onLineChartBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * che chiede come azione eseguita l'apertura di un LineChart
      * viene usato il modello attuale nel Ctrl
      */

     //void onLineChartBPressed()const;

     /**
      * @brief onBarChartBPressed SLOT eseguito alla ricezione di SEGNALI dalla view
      * che chiede come azione eseguita l'apertura di un BarChart
      * viene usato il modello attuale nel Ctrl
      */

    // void onBarChartBPressed(bool old) const;
};

#endif // TABLECTRL_H
