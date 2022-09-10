#include "venditectrl.h"

venditeCtrl::venditeCtrl(venditeView* v, tabelle* m, Ctrl* parent) : Ctrl(v,m,parent)
{
    connectViewCtrlSignalsSlots();

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

    connect(vista,SIGNAL(areaChartBPressed()),this,SLOT(onAreaChartBPressed()));

    connect(vista,SIGNAL(newVenditeProjectPressed()),this,SLOT(onVenditeNewProjectPressed()));
    connect(vista,SIGNAL(openVenditeProjectPressed()),this,SLOT(onVenditeOpenProjectPressed()));
    connect(vista,SIGNAL(saveVenditeProjectPressed()),this,SLOT(onVenditeSaveProjectPressed()));
    connect(vista,SIGNAL(saveVenditeProjectAsPressed()),this,SLOT(onVenditeSaveProjectAsPressed()));

}

venditeView* venditeCtrl::getView() const {
    return static_cast<venditeView*>(vista);
}

tabelle* venditeCtrl::getModel() const {
    return static_cast<tabelle*>(modello);
}

void venditeCtrl::onViewClosed() const {
    this->hideView();
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

void venditeCtrl::onAreaChartBPressed() const
{
    if(getModel()->getListaDatiVendite().size() == 0){
        vista->showWarningDialog("Attenzione","Inserire dei dati prima");
        return;
    }

    areaChart* aView = new areaChart(QSize(800,700),vista);
    modelAreaChart* aModel = new modelAreaChart(getModel());
    ctrlAreaChart* aCtrl = new ctrlAreaChart(aView,aModel,const_cast<venditeCtrl*>(this));
    aCtrl->showView();
}

void venditeCtrl::onVenditeNewProjectPressed() const{
    if(!vista->showQuestionDialog(3,"Nuovo Progetto","Vuoi aprire un nuovo progetto ?"))return;

    View* parentView = vista->parent() ? static_cast<View*>(vista->parent()) : nullptr;
    Ctrl* parentCtrl = parent() ? static_cast<Ctrl*>(parent()) : nullptr;

    venditeView* view = new venditeView(vista->size(),parentView);
    view->setViewTitle(tr("Nuovo"));
    view->setWindowSize(vista->size());
    venditeCtrl* ctrl = new venditeCtrl(view,new tabelle(),parentCtrl);
    ctrl->showView();
    vista->hide();
}

void venditeCtrl::onVenditeOpenProjectPressed() const{
    QString filepath = gestioneFileJSon::selectJSONFileDialog();
    if(filepath.isNull()){
        vista->showWarningDialog("Errore Apertura File", "Selezionare un file");
        return;
    }

    QJsonDocument* jsonData = gestioneFileJSon::getJSONFileVenditeData(filepath);
    if(jsonData->isNull()){
        vista->showWarningDialog("Errore Apertura File", "Riprova con un file valido");
        return;
    }

    //Apertura Nuova schermata Admin da progetto Salvato
    venditeView* view = new venditeView(vista->size(),vista);

    tabelle* model = new tabelle(new QString(filepath), jsonData, false);

    //Imposto il titolo alla schermata
    QStringList pieces = model->getPercorsoFile().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );


    venditeCtrl* ctrl = new venditeCtrl(view,model,nullptr);
    ctrl->showView();
    view->hide();

}

void venditeCtrl::onVenditeSaveProjectPressed() const{
    // Se il file non esiste, magari perchè è un nuovo progetto, salvo con nome
    if(getModel()->getPercorsoFile().isEmpty() || getModel()->getPercorsoFile().isNull()){
        onVenditeSaveProjectAsPressed();
        return;
    }

    //Imposto il titolo alla schermata
    QStringList pieces = getModel()->getPercorsoFile().split( "/" );
    QString last = pieces.value( pieces.length() - 1 );
    vista->setViewTitle(last);

    //effettuo il salvataggio ed in base all'esito mostro un messaggio
    bool esito = gestioneFileJSon::saveAdminModel(getModel()->venditeSaveToQJSonDocument(),getModel()->getPercorsoFile());
    if(!esito)
        vista->showCriticalDialog("Errore Salvataggio grave","Salvataggio NON riuscito");
    else
        vista->showInformationDialog("Perfetto !","Salvataggio Riuscito");
}

void venditeCtrl::onVenditeSaveProjectAsPressed() const{
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
    onVenditeSaveProjectPressed();
}


