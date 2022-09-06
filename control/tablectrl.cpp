#include "tablectrl.h"

tableCtrl::tableCtrl(tableView* v, tabelle* m, Ctrl* parent) : Ctrl(v,m,parent)
{
    //Collego i SIGNAL della View Ai SLOT del Controller
    connectViewCtrlSignalsSlots();

    //è essenziale che si crei prima la materialTable e solo poi la record table
    //Questo perchè in caso contrario si verificano dei problemi sulle QComboBox della
    //view che vengono registrati doppiamente.

    //Creo la Modelli Table
    getView()->createModelliTable({"MODELLO",""});

    //Creao Prima Row Pulsante Add
    getView()->addRowModelliTable(0);

    //Popo la ModelliTable con i dati presi da Model
    unsigned int id = 0;
    for (const QString& m : *getModel()->getListaModelli()) {
        getView()->addItemModelliTable(id++,m);
    }

    //Creo la Tessuti Table
    getView()->createTessutiTable({"TESSUTO",""});

    //Creao Prima Row Pulsante Add
    getView()->addRowTessutiTable(0);

    //Popo la TessutiTable con i dati presi da Model
    id = 0;
    for (const QString& t : *getModel()->getListaTessuti()) {
        getView()->addItemModelliTable(id++,t);
    }

    //Creao la Data Table
    getView()->createDataTable({ "Modello", "Tessuto", "Tessuto usato", "Costo Tessuto per Mq","Costo Base", "Costo Lavaggio", "Costo Vendita", "Produzione Giornaliera", ""});

    //Creo Prima Row Pulsante Add
    getView()->addRowDataTable(0,*getModel()->getListaModelli(), *getModel()->getListaTessuti());

    //Popolo La DataTable con i datiModelli presi da Model
    id = 0;
    for (datiModelli* d : getModel()->getListaDatiModelli()) {
        getView()->addItemDataTable(id++,*d,*getModel()->getListaModelli(), *getModel()->getListaTessuti());
    }
}


tableView* tableCtrl::getView() const {
    return static_cast<tableView*>(vista);
}

tabelle* tableCtrl::getModel() const {
    return static_cast<tabelle*>(modello);
}

void tableCtrl::connectViewCtrlSignalsSlots() const{

    //connessioni per la dataTable
    connect(vista,SIGNAL(dataTableRemoved(uint)),this,SLOT(onDataTableRemoved(uint)));
    connect(vista,SIGNAL(dataTableAdded(QString, QString, float, float, float, float, float, uint)),this,SLOT(onDataTableAdded(QString, QString, float, float, float, float, float, uint)));
    connect(vista,SIGNAL(dataTableModelloMod(uint,QString)),this,SLOT(onDataTableModelloMod(uint,QString)));
    connect(vista,SIGNAL(dataTableTessutoMod(uint,QString)),this,SLOT(onDataTableTessutoMod(uint,QString)));
    connect(vista,SIGNAL(dataTableTessUsatoMod(uint,uint)),this,SLOT(onDataTableTessUsatoMod(uint,float)));
    connect(vista,SIGNAL(dataTableCostoTessutoMod(uint,uint)),this,SLOT(onDataTableCostoTessutoMod(uint,float)));
    connect(vista,SIGNAL(dataTableCostoBaseMod(uint,uint)),this,SLOT(onDataTableCostoBaseMod(uint,float)));
    connect(vista,SIGNAL(dataTableCostoLavaggioMod(uint,uint)),this,SLOT(onDataTableCostoLavaggioMod(uint,float)));
    connect(vista,SIGNAL(dataTableCostoVenditaMod(uint,uint)),this,SLOT(onDataTableCostoVenditaMod(uint,float)));

    //connessioni per la ModelliTable
    connect(vista,SIGNAL(modelliTableAdded(QString)),this,SLOT(onModelliTableAdded(QString)));
    connect(vista,SIGNAL(modelliTableRemoved(uint)),this,SLOT(onModelliTableRemoved(uint)));
    connect(vista,SIGNAL(modelliTableModelloMod(uint,QString)),this,SLOT(onModelliTableModelloMod(uint,QString)));

    //connessioni per la TessutiTable


    //connessioni per i pulsanti di interrazione

}

void tableCtrl::onViewClosed() const {
    delete this;
}

void tableCtrl::onDataTableRemoved(unsigned int row){
    getModel()->rimuoviRigaModelli(row);
}

void tableCtrl::onDataTableAdded(const QString & m, const QString & t, float tU, float cT, float cB, float cL, float cV, unsigned int pG){
    datiModelli* d = new datiModelli(m, t, tU, cT, cB, cL, cV, pG);
    getModel()->aggiungiRigaModelli(d);
    getView()->addItemDataTable(getModel()->getListaDatiModelli().size()-1,*d,*getModel()->getListaModelli(), *getModel()->getListaTessuti());
}

void tableCtrl::onDataTableModelloMod(unsigned int row, const QString& m){
    //getModel()->get(row)->setModello(m);

}

void tableCtrl::onDataTableTessutoMod(unsigned int row, const QString& m){

}

void tableCtrl::onModelliTableAdded(const QString &m){
    for(const QString& mAdd : *getModel()->getListaModelli()){
        if(mAdd == m){
            getView()->showCriticalDialog("Inserimento Fallito","Inserimento non concesso\nassicurarsi che il nome sia univoco");
            return;
        }
    }
    getModel()->aggiungiModello(m);
    getView()->addItemModelliTable(getModel()->getListaModelli()->size()-1,m);
}

void tableCtrl::onModelliTableModelloMod(unsigned int row, const QString &m){

}

void tableCtrl::onModelliTableRemoved(unsigned int row){
}

