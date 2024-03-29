#include "tablectrl.h"

tableCtrl::tableCtrl(tableView* v, tabelle* m, Ctrl* parent) : Ctrl(v,m,parent)
{
    //Collego i SIGNAL della View Ai SLOT del Controller
    connectViewCtrlSignalsSlots();

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
    connect(vista,SIGNAL(dataTableAdded(QString, QString, double, double, double, double, double, uint)),this,SLOT(onDataTableAdded(QString, QString, double, double, double, double, double, uint)));
    connect(vista,SIGNAL(dataTableModelloMod(uint,QString)),this,SLOT(onDataTableModelloMod(uint,QString)));
    connect(vista,SIGNAL(dataTableTessutoMod(uint,QString)),this,SLOT(onDataTableTessutoMod(uint,QString)));
    connect(vista,SIGNAL(dataTableTessUsatoMod(uint,double)),this,SLOT(onDataTableTessUsatoMod(uint,double)));
    connect(vista,SIGNAL(dataTableCostoTessutoMod(uint,double)),this,SLOT(onDataTableCostoTessutoMod(uint,double)));
    connect(vista,SIGNAL(dataTableCostoBaseMod(uint,double)),this,SLOT(onDataTableCostoBaseMod(uint,double)));
    connect(vista,SIGNAL(dataTableCostoLavaggioMod(uint,double)),this,SLOT(onDataTableCostoLavaggioMod(uint,double)));
    connect(vista,SIGNAL(dataTableCostoVenditaMod(uint,double)),this,SLOT(onDataTableCostoVenditaMod(uint,double)));
    connect(vista,SIGNAL(dataTableProdGiornalieraMod(uint,uint)),this,SLOT(onDataTableProdGiornalieraMod(uint,uint)));

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
    connect(vista,SIGNAL(venditePressed()),this,SLOT(onVenditePressed()));
    connect(vista,SIGNAL(guidePressed()),this,SLOT(onGuidePressed()));

    connect(vista,SIGNAL(newProjectPressed()),this,SLOT(onNewProjectPressed()));
    connect(vista,SIGNAL(openProjectPressed()),this,SLOT(onOpenProjectPressed()));
    connect(vista,SIGNAL(saveProjectPressed()),this,SLOT(onSaveProjectPressed()));
    connect(vista,SIGNAL(saveProjectAsPressed()),this,SLOT(onSaveProjectAsPressed()));
    connect(vista,SIGNAL(exitPressed()),this,SLOT(onExitPressed()));

}

void tableCtrl::onViewClosed() const {
    delete this;
}

void tableCtrl::onDataTableRemoved(unsigned int row){
    getModel()->rimuoviRigaModelli(row);
}

void tableCtrl::onDataTableAdded(const QString & m, const QString & t, double tU, double cT, double cB, double cL, double cV, unsigned int pG){
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

void tableCtrl::onDataTableTessUsatoMod(unsigned int row, double tu){
    getModel()->getDatiModelli(row)->setTessutoUsato(tu);
}

void tableCtrl::onDataTableCostoTessutoMod(unsigned int row, double ct){
    getModel()->getDatiModelli(row)->setCostoTessutoMq(ct);
}

void tableCtrl::onDataTableCostoBaseMod(unsigned int row, double cb){
    getModel()->getDatiModelli(row)->setCostoBase(cb);
}

void tableCtrl::onDataTableCostoLavaggioMod(unsigned int row, double cl){
    getModel()->getDatiModelli(row)->setCostoLavaggio(cl);
}

void tableCtrl::onDataTableCostoVenditaMod(unsigned int row, double cv){
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


void tableCtrl::onVenditePressed() const
{
    venditeView* vView = new venditeView();
    venditeCtrl* vCtrl = new venditeCtrl(vView);
    vCtrl->showView();

}

void tableCtrl::onGuidePressed() const{
    GuideView* guida = new GuideView();
    guida->show();
}

void tableCtrl::onNewProjectPressed() const{
    if(!vista->showQuestionDialog(3,"Nuovo Progetto","Vuoi aprire un nuovo progetto ?"))return;

    View* parentView = vista->parent() ? static_cast<View*>(vista->parent()) : nullptr;
    Ctrl* parentCtrl = parent() ? static_cast<Ctrl*>(parent()) : nullptr;

    tableView* TableView = new tableView(vista->size(),parentView);
    TableView->setViewTitle(tr("Nuovo"));
    TableView->setWindowSize(vista->size());
    tableCtrl* TableControl = new tableCtrl(TableView,new tabelle(),parentCtrl);
    TableControl->showView();
    vista->hide();
}

void tableCtrl::onOpenProjectPressed() const{
    QString filepath = gestioneFileJSon::selectJSONFileDialog();
    if(filepath.isNull()){
        vista->showWarningDialog("Errore Apertura File", "Selezionare un file");
        return;
    }

    QJsonDocument* jsonData = gestioneFileJSon::getJSONFileModelData(filepath);
    if(jsonData->isNull()){
        vista->showWarningDialog("Errore Apertura File", "Riprova con un file valido "+ filepath);
        return;
    }

    //Apertura Nuova schermata Admin da progetto Salvato
    tableView* view = new tableView(vista->size(),vista);

    tabelle* model = new tabelle(new QString(filepath), jsonData, true);

    //Imposto il titolo alla schermata
    QStringList pieces = model->getPercorsoFile().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );   

    tableCtrl* ctrl = new tableCtrl(view,model,nullptr);
    ctrl->showView();
    vista->hide();

}

void tableCtrl::onSaveProjectPressed() const{
    // Se il file non esiste, magari perchè è un nuovo progetto, salvo con nome
    if(getModel()->getPercorsoFile().isEmpty() || getModel()->getPercorsoFile().isNull()){
        onSaveProjectAsPressed();
        return;
    }

    //Imposto il titolo alla schermata
    QStringList pieces = getModel()->getPercorsoFile().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );
    vista->setViewTitle(last);

    //effettuo il salvataggio ed in base all'esito mostro un messaggio
    bool esito = gestioneFileJSon::saveAdminModel(getModel()->modelSaveToQJSonDocument(),getModel()->getPercorsoFile());
    if(!esito)
        vista->showCriticalDialog("Errore Salvataggio grave","Salvataggio NON riuscito");
    else
        vista->showInformationDialog("Perfetto !","Salvataggio Riuscito");
}

void tableCtrl::onSaveProjectAsPressed() const{
    //Faccio la richiesta per il nume del file
    QString jsonFilter = "JSON Files (*.json)";
    QString titolo = QString::fromStdString("Salva file con nome");
    QString fname = QFileDialog::getSaveFileName(vista,titolo,QDir::homePath(),jsonFilter);

    //Verifico che il nume sia valido
    if(fname.isEmpty() || fname.isNull()){
        vista->showCriticalDialog("Errore Salvataggio","Salvataggio NON riuscito\nInserire un nome file valido");
        return;
    }

    if (!fname.endsWith(".json"))
        fname+= tr(".json");

    //Setto il nume del file al modello di dati
    getModel()->setPercosoFile(fname);

    //ora faccio il salvataggio automatico
    onSaveProjectPressed();
}

void tableCtrl::onExitPressed() const{
     vista->viewClosed();
}
