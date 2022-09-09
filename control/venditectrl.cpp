#include "venditectrl.h"

venditeCtrl::venditeCtrl(venditeView* v, tabelle* m, Ctrl* parent) : Ctrl(v,m,parent)
{
    //connectViewCtrlSignalsSlots();

    //creazione tabella venditeTable
    getView()->createVenditeTable({"Pezzi prodotti", "Pezzi venduti", "Data", ""});

    //inserimento prima riga venditeTable
    getView()->addRowVenditeTable(0);

    //Popolamento venditeTable
    unsigned int id = 0;
    for (datiVendite* dv : getModel()->getListaDatiVendite()) {
        getView()->addItemVenditeTable(id++,*dv);
    }
}

void venditeCtrl::connectViewCtrlSignalsSlots() const{
    //VENDITE TABLE
    connect(vista,SIGNAL(venditeTableAdded(uint, uint, QDate)),this,SLOT(onVenditeTableAdded(uint, uint, QDate)));
    connect(vista,SIGNAL(venditeTableRemoved(uint)),this,SLOT(onVenditeTableRemoved(uint)));
    connect(vista,SIGNAL(venditeTablePezziProdottiMod(uint, uint)),this,SLOT(onVenditeTablePezziProdottiMod(uint, uint)));
    connect(vista,SIGNAL(venditeTablePezziVendutiMod(uint, uint)),this,SLOT(onVenditeTablePezziVendutiMod(uint, uint)));
    connect(vista,SIGNAL(venditeTableDataMod(uint, QDate)),this,SLOT(onVenditeTableDataMod(uint, QDate)));

}

venditeView* venditeCtrl::getView() const {
    return static_cast<venditeView*>(vista);
}

tabelle* venditeCtrl::getModel() const {
    return static_cast<tabelle*>(modello);
}

void venditeCtrl::onViewClosed() const {
    delete this;
}

void venditeCtrl::onVenditeTableAdded(unsigned int pP, unsigned int pV, QDate data){
    datiVendite* dv = new datiVendite(pP,pV,data);
    getModel()->aggiungiRigaVendite(dv);
    getView()->addItemVenditeTable(getModel()->getListaDatiVendite().size()-1,*dv);
}

void venditeCtrl::onVenditeTableRemoved(unsigned int row){
    getModel()->rimuoviRigaVendite(row);
}

void venditeCtrl::onVenditeTablePezziProdottiMod(unsigned int row, unsigned int pP){
    getModel()->getDatiVendite(row)->setPezziProdotti(pP);
}

void venditeCtrl::onVenditeTablePezziVendutiMod(unsigned int row, unsigned int pV){
    getModel()->getDatiVendite(row)->setPezziVenduti(pV);
}

void venditeCtrl::onVenditeTableDataMod(unsigned int row, QDate data){
    getModel()->getDatiVendite(row)->setData(data);
}
