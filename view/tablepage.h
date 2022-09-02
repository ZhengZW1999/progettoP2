#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include "view/view.h"

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTableWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSize>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QSpinBox>
#include <QDateEdit>


class tablePage: public View
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;

    QTableWidget* dataTable;
    QTableWidget* modelliTable;
    QTableWidget* tessutiTable;

    QPushButton* pieChartBtn;
    QPushButton* barChartBtn;
    QPushButton* lineChartBtn;
    QPushButton* PosNegBarChartBtn;
    QPushButton* doubleBarChartBtn;


public:
    explicit tablePage(const QSize& s = QSize(), View* parent = nullptr);

    /**
     * @brief addRowDataTable Crea una riga specifica di add, alla riga row, in cui appone uno spazione nuovo su cui
     * si potrà inserire i dettagli di un nuovo record.
     * Associa in fine al pulsante + creato anche una connessione per Segnale la quale Aggiornerà anche il Model.
     * @param row riga a cui aggiungere la riga di add
     */
    void addRowDataTable(unsigned int row, const QStringList& listaModelli, const QStringList& listaTessuti);

    /**
     * @brief addItemDataTable Metodo che aggiunge una nuova riga alla dataTable.
     * Mostra ciascun dato con per ciascuno un input QT adeguato, e alla fine della riga l'ultima colonna
     * aggiunge un pulsante che serve ad eliminare la riga.
     *
     * @param row Riga in cui fare la aggiuntaa
     * @param r Record da aggiungere
     * @param listaModelli lista di modelli tra cui scegliere per la cella di selezione modelli
     * @param listaTessuti lista di modelli tra cui scegliere per la cella di selezione tessuti
     */
    void addItemDataTable(unsigned int row,const datiModelli& d, const datiVendite& dv, const QStringList& listaModelli, const QStringList& listaTessuti );

    /**
     * @brief addRowModelliTable Metodo che si occupa di creare la riga di inserimento dei materiali, in questa
     * riga si potranno inserire i dettagli di un nuovo materiale
     * @param row riga alla cui creare
     */
    void addRowModelliTable(unsigned int row);


    /**
     * @brief addItemModelliTable Metodo che aggiunge ad una QTableWidget,
     * in particolare alla modelliTable, aggiunge un Modello di dato specifico cioè un QString preso dal Model.
     * Questa aggiunta avviene ad una riga precisa della tabella row.
     * Attenzione che si occupa anche di associare un pulsante ad ogni Riga.
     * Attenzione che si occupa anche di associare nelle connessioni di signali ai pulsanti e alla modifica dei campi
     * @param row
     * @param m
     */
    void addItemModelliTable(unsigned int row, const QString& m);

    /**
     * @brief addRowTessutiTable Metodo che si occupa di creare la riga di inserimento dei materiali, in questa
     * riga si potranno inserire i dettagli di un nuovo materiale
     * @param row riga alla cui creare
     */
    void addRowTessutiTable(unsigned int row);
    /**
     * @brief addItemTessutiTable Metodo che aggiunge ad una QTableWidget,
     * in particolare alla modelliTable, aggiunge un Modello di dato specifico cioè un QString preso dal Model.
     * Questa aggiunta avviene ad una riga precisa della tabella row.
     * Attenzione che si occupa anche di associare un pulsante ad ogni Riga.
     * Attenzione che si occupa anche di associare nelle connessioni di signali ai pulsanti e alla modifica dei campi
     * @param row
     * @param m
     */
    void addItemTessutiTable(unsigned int row, const QString& t);

    /**
     * @brief modifyItemModelliTable Metodo che modifica uno specifico Modello
     * della modelliTable
     * Infine viene emesso un segnale per aggiornare anche i QComboBox con la modifica
     * da fare al modello
     * @param row
     * @param m
     */
    void modifyItemModelliTable(unsigned int row, const QString& m);

    /**
     * @brief removeItemModelliTable Metodo che elimina un item della record table
     * Viene emmesso il segnale modelliTableRemovedChecked(row) per aggiornare
     * i QComboBox per il modello della dataTable
     * @param row riga del Modello da rimuovere
     */
    void removeItemModelliTable(unsigned int row);

    /**
     * @brief modifyItemTessutiTable Metodo che modifica uno specifico Tessuto
     * della tessutiTable
     * Infine viene emesso un segnale per aggiornare anche i QComboBox con la modifica
     * da fare al tessuto
     * @param row
     * @param m
     */
    void modifyItemTessutiTable(unsigned int row, const QString& m);

    /**
     * @brief removeItemTessutiTable Metodo che elimina un item della data table
     * Viene emmesso il segnale tessutiTableRemovedChecked(row) per aggiornare
     * i QComboBox per il tessuto della dataTable
     * @param row riga del Tessuto da rimuovere
     */
    void removeItemTessutiTable(unsigned int row);


signals:
    //SIGNAL catturatti da un Controller, servono per aggiornare il Model con la modifica della dataTable
    void dataTableRemoved(uint) const;
    void dataTableAdded(QString, uint, uint, QDate) const;

    void dataTableModelloMod(uint, QString) const;
    void dataTableTessutoMod(uint, QString) const;
    void dataTableTessUsatoMod(uint, uint) const;
    void dataTableCostoTessutoMod(uint, uint) const;
    void dataTableCostoBaseMod(uint, uint) const;
    void dataTableCostoLavaggioMod(uint, uint) const;
    void dataTableCostoVenditaMod(uint, uint) const;

    void dataTablePezziProdottiMod(uint, uint) const;
    void dataTablePezziVendutiMod(uint, uint) const;

    void dataTableDataMod(uint, QDate) const;

    //SIGNAL catturati da un Controller, servono per aggiornare il Model con la modifica delle modelliTable e tessutiTable
    void modelliTableAdded(QString) const;
    void modelliTableModelloMod(uint,QString) const;
    void modelliTableRemoved(uint) const;

    void tessutiTableAdded(QString) const;
    void tessutiTableTessutoMod(uint,QString) const;
    void tessutiTableRemoved(uint) const;

    //SIGNAL catturati dalla View, servono per aggiornare i QComboBox con la modifica dei campo dati Modello e Tessuto della dataTable
    void modelliTableAddedChecked(QString) const;
    void modelliTableRemovedChecked(uint) const;
    void modelliTableModelloModChecked(uint,QString) const;

    void tessutiTableAddedChecked(QString) const;
    void tessutiTableRemovedChecked(uint) const;
    void tessutiTableTessutoModChecked(uint,QString) const;

};


#endif // TABLEPAGE_H
