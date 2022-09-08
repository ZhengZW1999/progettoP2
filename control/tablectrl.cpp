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
        getView()->addItemTessutiTable(id++,t);
    }

    //Creo la Data Table
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
    connect(vista,SIGNAL(tessutiTableAdded(QString)),this,SLOT(onTessutiTableAdded(QString)));
    connect(vista,SIGNAL(tessutiTableRemoved(uint)),this,SLOT(onTessutiTableRemoved(uint)));
    connect(vista,SIGNAL(tessutiTableTessutoMod(uint,QString)),this,SLOT(onTessutiTableTessutoMod(uint,QString)));

    //connessioni per i pulsanti di interrazione
    connect(vista,SIGNAL(barChartBPressed()),this,SLOT(onBarChartBPressed()));
    connect(vista,SIGNAL(lineChartBPressed()),this,SLOT(onLineChartBPressed()));
    connect(vista,SIGNAL(pieChartBPressed()),this,SLOT(onPieChartBPressed()));
    connect(vista,SIGNAL(stackedBarChartBPressed()),this,SLOT(onStackedBarChartBPressed()));
    connect(vista,SIGNAL(guidePressed()),this,SLOT(onGuidePressed()));

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
    getModel()->getDatiModelli(row)->setNomeModello(m);

}

void tableCtrl::onDataTableTessutoMod(unsigned int row, const QString& t){
    getModel()->getDatiModelli(row)->setTessuto(t);
}

void tableCtrl::onDataTableTessUsatoMod(unsigned int row, float tu){
    getModel()->getDatiModelli(row)->setTessutoUsato(tu);
}

void tableCtrl::onDataTableCostoTessutoMod(unsigned int row, float ct){
    getModel()->getDatiModelli(row)->setCostoTessutoMq(ct);
}

void tableCtrl::onDataTableCostoBaseMod(unsigned int row, float cb){
    getModel()->getDatiModelli(row)->setCostoBase(cb);
}

void tableCtrl::onDataTableCostoLavaggioMod(unsigned int row, float cl){
    getModel()->getDatiModelli(row)->setCostoLavaggio(cl);
}

void tableCtrl::onDataTableCostoVenditaMod(unsigned int row, float cv){
    getModel()->getDatiModelli(row)->setCostoVendita(cv);
}

void tableCtrl::onDataTableProdGiornalieraMod(unsigned int row, unsigned int pd){
    getModel()->getDatiModelli(row)->setProduzioneGiornaliera(pd);
}

void tableCtrl::onModelliTableAdded(const QString &m){
    for(const QString& mAdd : *getModel()->getListaModelli()){
        if(mAdd == m){
            getView()->showCriticalDialog("Errore","Modello gia' esistente");
            return;
        }
    }
    getModel()->aggiungiModello(m);
    getView()->addItemModelliTable(getModel()->getListaModelli()->size()-1,m);
}

void tableCtrl::onModelliTableModelloMod(unsigned int row, const QString &m){
    //contatore per cercare duplicati
    unsigned int counter = 0;
    for(const QString& mAdd : *getModel()->getListaModelli()){

        if(mAdd == m && counter != row){    //duplicato
            getModel()->setModello(row,m);
            getView()->showWarningDialog("Warning","Modello gia' esistente");
            getView()->modifyItemModelliTable(row,m+"?");
            return;
        }
        else if(mAdd == m && counter == row)
            return;
        counter++;
    }

    //non c'e' duplicato
    getModel()->setModello(row,m);
    emit getView()->modelliTableModelloModChecked(row,m);
}

void tableCtrl::onModelliTableRemoved(unsigned int row){
    QString m = getModel()->getModello(row);
    for(datiModelli* r : getModel()->getListaDatiModelli()){
        if(r->getNomeModello() == m){
            getView()->showCriticalDialog("Errore","Il modello e' in uso nella tabella Dati");
            return;
        }
    }
    getView()->removeItemModelliTable(row);
    getModel()->rimuoviModello(row);
}


void tableCtrl::onTessutiTableAdded(const QString &t){
    for(const QString& tAdd : *getModel()->getListaTessuti()){
        if(tAdd == t){
            getView()->showCriticalDialog("Errore","Tessuto gia' esistente");
            return;
        }
    }
    getModel()->aggiungiTessuto(t);
    getView()->addItemTessutiTable(getModel()->getListaTessuti()->size()-1,t);
}

void tableCtrl::onTessutiTableTessutoMod(unsigned int row, const QString &t){
    //contatore per cercare duplicati
    unsigned int counter = 0;
    for(const QString& tAdd : *getModel()->getListaTessuti()){

        if(tAdd == t && counter != row){    //duplicato
            getModel()->setTessuto(row,t);
            getView()->showWarningDialog("Warning","Tessuto gia' esistente");
            getView()->modifyItemTessutiTable(row,t+"?");
            return;
        }
        else if(tAdd == t && counter == row)
            return;
        counter++;
    }

    //non c'e' duplicato
    getModel()->setTessuto(row,t);
    emit getView()->tessutiTableTessutoModChecked(row,t);
}

void tableCtrl::onTessutiTableRemoved(unsigned int row){
    QString m = getModel()->getTessuto(row);
    for(datiModelli* r : getModel()->getListaDatiModelli()){
        if(r->getTessuto() == m){
            getView()->showCriticalDialog("Errore","Il tessuto e' in uso nella tabella Dati");
            return;
        }
    }
    getView()->removeItemTessutiTable(row);
    getModel()->rimuoviTessuto(row);
}

void tableCtrl::onBarChartBPressed() const
{
    if(getModel()->getListaDatiModelli().size() == 0){
        vista->showWarningDialog("Attenzione","Inserire dei dati prima");
        return;
    }

    barChart* bView = new barChart(QSize(800,700),vista);
    modelBarChart* bModel = new modelBarChart(getModel());
    ctrlBarChart* bCtrl = new ctrlBarChart(bView,bModel,const_cast<tableCtrl*>(this));
    bCtrl->showView();
}

void tableCtrl::onLineChartBPressed() const
{
    if(getModel()->getListaDatiModelli().size() == 0){
        vista->showWarningDialog("Attenzione","Inserire dei dati prima");
        return;
    }

    lineChart* lView = new lineChart(QSize(800,700),vista);
    modelLineChart* lModel = new modelLineChart(getModel());
    ctrlLineChart* lCtrl = new ctrlLineChart(lView,lModel,const_cast<tableCtrl*>(this));
    lCtrl->showView();
}

void tableCtrl::onStackedBarChartBPressed() const
{
    if(getModel()->getListaDatiModelli().size() == 0){
        vista->showWarningDialog("Attenzione","Inserire dei dati prima");
        return;
    }

    stackedBarChart* sbView = new stackedBarChart(QSize(800,700),vista);
    modelStackedBarChart* sbModel = new modelStackedBarChart(getModel());
    ctrlStackedBarChart* sbCtrl = new ctrlStackedBarChart(sbView,sbModel,const_cast<tableCtrl*>(this));
    sbCtrl->showView();
}

void tableCtrl::onPieChartBPressed() const
{
    if(getModel()->getListaDatiModelli().size() == 0){
        vista->showWarningDialog("Attenzione","Inserire dei dati prima");
        return;
    }

    pieChart* pView = new pieChart(QSize(800,700),vista);
    modelPieChart* pModel = new modelPieChart(getModel());
    ctrlPieChart* pCtrl = new ctrlPieChart(pView,pModel,const_cast<tableCtrl*>(this));
    pCtrl->showView();
}


