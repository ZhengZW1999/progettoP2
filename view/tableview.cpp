#include "tableview.h"

void tableView::closeEvent(QCloseEvent* event){
    //Elaboro chiusura solo se intenzionata da evento esterno
    if(!event->spontaneous()) return;

    if(!showQuestionDialog(3,"Exit","Sei sicuro di voler uscire?\n")){
        //Ignoro l'evento di chiusura
        event->ignore();
    } else {
        //Accetto l'evento di chiusura della Window
        event->accept();
        emit viewClosed();
    }
}

void tableView::connectViewSignals() const{
    connect(barChartBtn,SIGNAL(clicked()),this,SIGNAL(barChartBPressed()));
    connect(pieChartBtn,SIGNAL(clicked()),this,SIGNAL(pieChartBPressed()));
    connect(stackedBarChartBtn,SIGNAL(clicked()),this,SIGNAL(stackedBarChartBPressed()));
    connect(lineChartBtn,SIGNAL(clicked()),this,SIGNAL(lineChartBPressed()));
    connect(venditeBtn,SIGNAL(clicked()),this,SIGNAL(venditePressed()));

    connect(guida,SIGNAL(clicked()),this,SIGNAL(guidePressed()));

    connect(newProject, SIGNAL(triggered()), this, SIGNAL(newProjectPressed()));
    connect(openProject, SIGNAL(triggered()), this, SIGNAL(openProjectPressed()));
    connect(saveProject, SIGNAL(triggered()), this, SIGNAL(saveProjectPressed()));
    connect(saveProjectAs, SIGNAL(triggered()), this, SIGNAL(saveProjectAsPressed()));
    connect(Exit, SIGNAL(triggered()), this, SIGNAL(exitPressed()));
}
tableView::tableView(const QSize& s, View* parent): View(s,parent)
{
    mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setSpacing(3);


    //aggiungere la barra del menu

    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);

    menuBar->addMenu(file);


    //MENU FILE
    newProject = new QAction("New Project...", file);
    openProject = new QAction("Open Project...", file);
    saveProject = new QAction("Save Project", file);
    saveProjectAs = new QAction("Save Project As...", file);
    Exit = new QAction("Exit...", file);
    file->addAction(newProject);
    file->addAction(openProject);
    file->addAction(saveProject);
    file->addAction(saveProjectAs);
    file->addAction(Exit);


    mainLayout->addWidget(menuBar);

    //aggiungere layout i widget tabella dati e tabelle modelli e tessuti
    QVBoxLayout* innerLayout = new QVBoxLayout;
    QHBoxLayout* materialiLayout = new QHBoxLayout;
    QVBoxLayout* buttonLayout = new QVBoxLayout;

    //CREAZIONE TABELLE
    dataTable = new QTableWidget;
    modelliTable = new QTableWidget;
    tessutiTable = new QTableWidget;

    //PULSANTI PER CREARE GRAFICI
    pieChartBtn = new QPushButton("Numero di volte del tessuto utilizzato");
    barChartBtn = new QPushButton("Composizione costo vendita per modello");
    lineChartBtn = new QPushButton("ProdGiorn di ogni modello");
    stackedBarChartBtn = new QPushButton("Costo vendita / costo finale");
    venditeBtn = new QPushButton("Produzione / vendita per ogni mese");
    guida = new QPushButton("Guida");

    innerLayout->addWidget(dataTable);

    materialiLayout->addWidget(modelliTable);
    materialiLayout->addWidget(tessutiTable);
    materialiLayout->addLayout(materialiLayout);

    //Sezione destra con i pulsanti
    buttonLayout->addWidget(pieChartBtn);
    buttonLayout->addWidget(barChartBtn);
    buttonLayout->addWidget(lineChartBtn);
    buttonLayout->addWidget(venditeBtn);
    buttonLayout->addWidget(stackedBarChartBtn);
    buttonLayout->addWidget(guida);
    buttonLayout->setMargin(20);
    buttonLayout->setSpacing(10);

     //materialiLayout->setMargin(0);

    innerLayout->addLayout(materialiLayout);
    materialiLayout->addLayout(buttonLayout);

    mainLayout->addLayout(innerLayout);


    setLayout(mainLayout);

    //Connessione dei SIGNAL
    connectViewSignals();
}

//CREAZIONE TABELLE
void tableView::createDataTable(const QStringList& headers) const{
    dataTable->setMinimumHeight(400);
    dataTable->setMinimumWidth(1500);
    dataTable->setRowCount(0);
    dataTable->setColumnCount(9);
    dataTable->setColumnWidth(3,200);
    dataTable->setColumnWidth(7,200);
    dataTable->setColumnWidth(8,30);
    dataTable->resizeColumnsToContents();
    dataTable->setHorizontalHeaderLabels(headers);
    dataTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    dataTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    dataTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    dataTable->horizontalHeader()->setStretchLastSection(false);
}

void tableView::createModelliTable(const QStringList& headers) const{
    modelliTable->setRowCount(0);
    modelliTable->setColumnCount(2);
    modelliTable->setHorizontalHeaderLabels(headers);
    modelliTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    modelliTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}

void tableView::createTessutiTable(const QStringList& headers) const{
    tessutiTable->setRowCount(0);
    tessutiTable->setColumnCount(2);
    tessutiTable->setHorizontalHeaderLabels(headers);
    tessutiTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    tessutiTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}


//INSERIMENTO MODELLI NELLA TABELLA DATI (dataTable)

//CREAZIONE NUOVA RIGA PER INSERIMENTO DI UN NUOVO MODELLO NELLA TABELLA DATI (dataTable)
void tableView::addRowDataTable(unsigned int row, const QStringList& listaModelli, const QStringList& listaTessuti){
    //Inserismo una nuova riga per fare spazio
    dataTable->insertRow(row);

    //modelliTable e tessutiTable con la combo select box
    QComboBox* modelloW = new QComboBox(this);
    QComboBox* tessutoW = new QComboBox(this);

    //Aggiungo la lista degli elementi tra cui scegliere
    modelloW->addItems(listaModelli);
    tessutoW->addItems(listaTessuti);

    //Imposto il widget sulla cella
    dataTable->setCellWidget(row,0,modelloW);
    dataTable->setCellWidget(row,1,tessutoW);

    //Aggiornamento della lista di modelli alla aggiunta di un modello
    connect(this,&tableView::modelliTableAddedChecked,modelloW,[modelloW](const QString& m){
        modelloW->addItem(m);
    });
    //Aggiornamento della lista di modelli alla rimozione di un modello
    connect(this,&tableView::modelliTableRemovedChecked,modelloW,[modelloW](uint i){
        modelloW->removeItem(i);
    });
    //Aggiornamento della lista di modelli alla modifica di un modello
    connect(this,&tableView::modelliTableModelloModChecked,modelloW,[modelloW](uint i, const QString& m){
        //verifico se l'elemento attualmente selezionato è quello da modificare, adrà poi riselezionato
        bool iSelected = (modelloW->currentIndex() == (int)i);
        modelloW->removeItem(i);
        modelloW->insertItem(i,m);
        if(iSelected)
            modelloW->setCurrentIndex(i);
    });

    //Aggiornamento della lista di tessuti alla aggiunta di un tessuto
    connect(this,&tableView::tessutiTableAddedChecked,tessutoW,[tessutoW](const QString& m){
        tessutoW->addItem(m);
    });
    //Aggiornamento della lista di tessuti alla rimozione di un tessuto
    connect(this,&tableView::tessutiTableRemovedChecked,tessutoW,[tessutoW](uint i){
        tessutoW->removeItem(i);
    });
    //Aggiornamento della lista di tessuti alla modifica di un tessuto
    connect(this,&tableView::tessutiTableTessutoModChecked,tessutoW,[tessutoW](uint i, const QString& m){
        //verifico se l'elemento attualmente selezionato è quello da modificare, adrà poi riselezionato
        bool iSelected = (tessutoW->currentIndex() == (int)i);
        tessutoW->removeItem(i);
        tessutoW->insertItem(i,m);
        if(iSelected)
            tessutoW->setCurrentIndex(i);
    });

    //WIDGETS
    QDoubleSpinBox* tessUsatoW = new QDoubleSpinBox(this);
    tessUsatoW->setRange(0,9999);
    tessUsatoW->setDecimals(1);
    tessUsatoW->setSingleStep(0.1);
    tessUsatoW->setSuffix(" Mq");
    dataTable->setCellWidget(row,2,tessUsatoW);

    QDoubleSpinBox* costoTessMqW = new QDoubleSpinBox(this);
    costoTessMqW->setRange(0,9999);
    costoTessMqW->setDecimals(1);
    costoTessMqW->setSingleStep(0.1);
    costoTessMqW->setSuffix(" euro ");
    dataTable->setCellWidget(row,3,costoTessMqW);

    QDoubleSpinBox* costoBaseW = new QDoubleSpinBox(this);
    costoBaseW->setRange(0,9999);
    costoBaseW->setDecimals(1);
    costoBaseW->setSingleStep(0.1);
    costoBaseW->setSuffix(" euro ");
    dataTable->setCellWidget(row,4,costoBaseW);

    QDoubleSpinBox* costoLavaggioW = new QDoubleSpinBox(this);
    costoLavaggioW->setRange(0,9999);
    costoLavaggioW->setDecimals(1);
    costoLavaggioW->setSingleStep(0.1);
    costoLavaggioW->setSuffix(" euro ");
    dataTable->setCellWidget(row,5,costoLavaggioW);

    QDoubleSpinBox* costoVenditaW = new QDoubleSpinBox(this);
    costoVenditaW->setRange(0,9999);
    costoVenditaW->setDecimals(1);
    costoVenditaW->setSingleStep(0.1);
    costoVenditaW->setSuffix(" euro ");
    dataTable->setCellWidget(row,6,costoVenditaW);

    QSpinBox* produzioneGiornalieraW = new QSpinBox(this);
    produzioneGiornalieraW->setRange(0,9999);
    //produzioneGiornaliera->setSuffix("");
    dataTable->setCellWidget(row,7,produzioneGiornalieraW);

    //Add Button Widget
    QPushButton* addW = new QPushButton("+",this);
    dataTable->setCellWidget(row,8,addW);

    connect(addW, &QPushButton::clicked,this,
            [this, modelloW, tessutoW, tessUsatoW, costoTessMqW, costoBaseW, costoLavaggioW, costoVenditaW, produzioneGiornalieraW]() {
        if(modelloW->currentIndex() != -1 && tessutoW->currentIndex() != -1)
            emit dataTableAdded(modelloW->currentText(), tessutoW->currentText(), tessUsatoW->value(), costoTessMqW->value(), costoBaseW->value(), costoLavaggioW->value(), costoVenditaW->value(), produzioneGiornalieraW->value());
        else
           showCriticalDialog("Inserimento non concesso","Inserire prima dei modelli e tessuti");
    });
}

//CREA UNA NUOVA RIGA CON I DATI E CON IL PULSANTE PER ELIMINARE RIGA NELLA TABELLA DATI (dataTable)
void tableView::addItemDataTable(unsigned int row,const datiModelli& d, const QStringList& listaModelli, const QStringList& listaTessuti){
    //Creo La ADD Row più in basso
    addRowDataTable(row+1,listaModelli, listaTessuti);

    //Modelli Table con la combo select box
    QComboBox* modelloW = new QComboBox(this);
    //Aggiungo la lista degli elementi tra cui scegliere
    modelloW->addItems(listaModelli);
    //Seleziono l'elemento predefinito scelto
    int indexModello = modelloW->findText(d.getNomeModello());
    if(indexModello != -1)
        modelloW->setCurrentIndex(indexModello);
    //Imposto il widget sulla cella
    dataTable->setCellWidget(row,0,modelloW);


    //Aggiornamento della lista di modelli alla aggiunta di un modello dalla listaModelli
    connect(this,&tableView::modelliTableAddedChecked,modelloW,[modelloW](const QString& m){
        modelloW->addItem(m);
    });
    //Aggiornamento della lista di modelli alla rimozione di un modello dalla listaModelli
    connect(this,&tableView::modelliTableRemovedChecked,modelloW,[modelloW](uint i){
        modelloW->removeItem(i);
    });
    //Aggiornamento della lista di modelli alla modifica di un modello
    connect(this,&tableView::modelliTableModelloModChecked,modelloW,[modelloW](uint i, const QString& m){
        //verifico se l'elemento attualmente selezionato è quello da modificare, sarà poi riselezionato
        bool iSelected = (modelloW->currentIndex() == (int)i);
        modelloW->removeItem(i);
        modelloW->insertItem(i,m);
        if(iSelected)
            modelloW->setCurrentIndex(i);
    });

    connect(modelloW, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[this,modelloW]() {
        unsigned int row = dataTable->indexAt(modelloW->pos()).row();
        emit dataTableModelloMod(row,modelloW->currentText());
    });

    //Tessuti Table con la combo select box
    QComboBox* tessutoW = new QComboBox(this);
    //Aggiungo la lista degli elementi tra cui scegliere
    tessutoW->addItems(listaTessuti);
    //Seleziono l'elemento predefinito scelto
    int indexTessuto = tessutoW->findText(d.getTessuto());
    if(indexTessuto != -1)
        tessutoW->setCurrentIndex(indexTessuto);
    //Imposto il widget sulla cella
    dataTable->setCellWidget(row,1,tessutoW);


    //Aggiornamento della lista di tessuti alla aggiunta di un tessuto dalla listaTessuti
    connect(this,&tableView::tessutiTableAddedChecked,tessutoW,[tessutoW](const QString& m){
        tessutoW->addItem(m);
    });
    //Aggiornamento della lista di tessuti alla rimozione di un tessuto dalla listaTessuti
    connect(this,&tableView::tessutiTableRemovedChecked,tessutoW,[tessutoW](uint i){
        tessutoW->removeItem(i);
    });
    //Aggiornamento della lista di tessuti alla modifica di un tessuto
    connect(this,&tableView::tessutiTableTessutoModChecked,tessutoW,[tessutoW](uint i, const QString& m){
        //verifico se l'elemento attualmente selezionato è quello da modificare, sarà poi riselezionato
        bool iSelected = (tessutoW->currentIndex() == (int)i);
        tessutoW->removeItem(i);
        tessutoW->insertItem(i,m);
        if(iSelected)
            tessutoW->setCurrentIndex(i);
    });

    connect(tessutoW, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),this,[this,tessutoW]() {
        unsigned int row = dataTable->indexAt(tessutoW->pos()).row();
        emit dataTableTessutoMod(row,tessutoW->currentText());
    });

    //tessUsato Widget
    QDoubleSpinBox* tessUsatoW = new QDoubleSpinBox(this);
    tessUsatoW->setRange(0,9999);
    tessUsatoW->setDecimals(1);
    tessUsatoW->setSingleStep(0.1);
    tessUsatoW->setSuffix(" Mq ");
    tessUsatoW->setValue(d.getTessUsato());
    dataTable->setCellWidget(row,2,tessUsatoW);

    connect(tessUsatoW, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,tessUsatoW](int value) {
        unsigned int row = dataTable->indexAt(tessUsatoW->pos()).row();
        emit dataTableTessUsatoMod(row,value);
        //tessUsatoW->value() == value
    });

    //costoTessutoMq Widget
    QDoubleSpinBox* costoTessutoMqW = new QDoubleSpinBox(this);
    costoTessutoMqW->setRange(0,9999);
    costoTessutoMqW->setDecimals(1);
    costoTessutoMqW->setSingleStep(0.1);
    costoTessutoMqW->setSuffix(" euro ");
    costoTessutoMqW->setValue(d.getCostoTessutoMq());
    dataTable->setCellWidget(row,3,costoTessutoMqW);

    connect(costoTessutoMqW, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,costoTessutoMqW](int value) {
        unsigned int row = dataTable->indexAt(costoTessutoMqW->pos()).row();
        emit dataTableCostoTessutoMod(row,value);
        //costoTessutoMqW->value() == value
    });

    //costoBase Widget
    QDoubleSpinBox* costoBaseW = new QDoubleSpinBox(this);
    costoBaseW->setRange(0,9999);
    costoBaseW->setDecimals(1);
    costoBaseW->setSingleStep(0.1);
    costoBaseW->setSuffix(" euro ");
    costoBaseW->setValue(d.getCostoBase());
    dataTable->setCellWidget(row,4,costoBaseW);

    connect(costoBaseW, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,costoBaseW](int value) {
        unsigned int row = dataTable->indexAt(costoBaseW->pos()).row();
        emit dataTableCostoBaseMod(row,value);
        //costoBaseW->value() == value
    });

    //costoLavaggio Widget
    QDoubleSpinBox* costoLavaggioW = new QDoubleSpinBox(this);
    costoLavaggioW->setRange(0,9999);
    costoLavaggioW->setDecimals(1);
    costoLavaggioW->setSingleStep(0.1);
    costoLavaggioW->setSuffix(" euro ");
    costoLavaggioW->setValue(d.getCostoLavaggio());
    dataTable->setCellWidget(row,5,costoLavaggioW);

    connect(costoLavaggioW, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,costoLavaggioW](int value) {
        unsigned int row = dataTable->indexAt(costoLavaggioW->pos()).row();
        emit dataTableCostoLavaggioMod(row,value);
        //costoLavaggioW->value() == value
    });

    //costoVendita Widget
    QDoubleSpinBox* costoVenditaW = new QDoubleSpinBox(this);
    costoVenditaW->setRange(0,9999);
    costoVenditaW->setDecimals(1);
    costoVenditaW->setSingleStep(0.1);
    costoVenditaW->setSuffix(" euro ");
    costoVenditaW->setValue(d.getCostoVendita());
    dataTable->setCellWidget(row,6,costoVenditaW);

    connect(costoVenditaW, static_cast<void(QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),this,[this,costoVenditaW](int value) {
        unsigned int row = dataTable->indexAt(costoVenditaW->pos()).row();
        emit dataTableCostoVenditaMod(row,value);
        //costoVenditaW->value() == value
    });

    QSpinBox* prodGiornalieraW = new QSpinBox(this);
    prodGiornalieraW->setRange(0,100000);
    prodGiornalieraW->setSuffix(" pezzi ");
    prodGiornalieraW->setValue(d.getProduzioneGiornaliera());
    dataTable->setCellWidget(row,7,prodGiornalieraW);

    connect(prodGiornalieraW, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,[this,prodGiornalieraW](int value) {
        unsigned int row = dataTable->indexAt(prodGiornalieraW->pos()).row();
        emit dataTableProdGiornalieraMod(row,value);
        //prodGiornalieraW->value() == value
    });


    //Delete Button Widget
    QPushButton* deleteW = new QPushButton("-",this);
    dataTable->setCellWidget(row,8,deleteW);//Widget

    //Connessione al pulsante delete per eliminare la riga e aggiornare il modello di dati con l'eliminazione
    connect(deleteW, &QPushButton::clicked,this,[this,deleteW]() {
        unsigned int row = dataTable->indexAt(deleteW->pos()).row();
        emit dataTableRemoved(row);
        dataTable->removeRow(row);
    });
}


//CREAZIONE NUOVA RIGA PER INSERIMENTO DI UN NUOVO MODELLO NELLA TABELLA MODELLI (modelliTable)
void tableView::addRowModelliTable(unsigned int row){
    //Inserismo una nuova riga per fare spazio
    modelliTable->insertRow(row);

    QTextEdit* modelloW = new QTextEdit(this);
   modelliTable->setCellWidget(row,0,modelloW);

    //ADD Button Widget
    QPushButton* addW = new QPushButton("+",this);
    modelliTable->setCellWidget(row,1,addW);

    connect(addW, &QPushButton::clicked,
            [this, modelloW]() {
        if(modelloW->toPlainText().isNull() || modelloW->toPlainText().isEmpty())
            showCriticalDialog("Inserimento Non Concesso", "Inserire un nome valido");
        else
            emit modelliTableAdded(modelloW->toPlainText());
    });
}

//CREA UNA NUOVA RIGA E AGGIUNGE IL WIDGET DI TESTO E UN PULSANTE PER LA ELIMINAZIONE DELLA RIGA NELLA TABELLA MODELLI (modelliTable)
void tableView::addItemModelliTable(unsigned int row,const QString& m){
    //Creo La ADD Row più in basso
    addRowModelliTable(row+1);


    QTextEdit* modelloW = new QTextEdit(this);
    modelloW->setText(m);
    modelliTable->setCellWidget(row,0,modelloW);

    connect(modelloW, &QTextEdit::textChanged,[this,modelloW]() {
        unsigned int row = modelliTable->indexAt(modelloW->pos()).row();
        emit modelliTableModelloMod(row,modelloW->toPlainText());
    });

    //Delete Button Widget
    QPushButton* deleteW = new QPushButton("-",this);

    modelliTable->setCellWidget(row,1,deleteW);//Widget

    connect(deleteW, &QPushButton::clicked,[this,deleteW]() {
        unsigned int row = modelliTable->indexAt(deleteW->pos()).row();
        emit modelliTableRemoved(row);

    });


    emit modelliTableAddedChecked(m);
}

void tableView::modifyItemModelliTable(unsigned int row, const QString &m){
    QTextEdit* textEdit = static_cast<QTextEdit*>(modelliTable->cellWidget(row,0));
    textEdit->setText(m);
    emit modelliTableModelloModChecked(row,m);
}

void tableView::removeItemModelliTable(unsigned int row){
    modelliTable->removeRow(row);
    emit modelliTableRemovedChecked(row);
}

//INSERIMENTO MODELLI NELLA TABELLA TESSUTI (tessutiTable)

//CREAZIONE NUOVA RIGA PER INSERIMENTO DI UN NUOVO MODELLO NELLA TABELLA TESSUTI (tessutiTable)
void tableView::addRowTessutiTable(unsigned int row){
    //Inserismo una nuova riga per fare spazio
    tessutiTable->insertRow(row);

    QTextEdit* tessutoW = new QTextEdit(this);
    tessutiTable->setCellWidget(row,0,tessutoW);

    //ADD Button Widget
    QPushButton* addW = new QPushButton("+",this);
    tessutiTable->setCellWidget(row,1,addW);

    connect(addW, &QPushButton::clicked,
            [this, tessutoW]() {
        if(tessutoW->toPlainText().isNull() || tessutoW->toPlainText().isEmpty())
            showCriticalDialog("Inserimento Non Concesso", "Inserire un nome valido");
        else
            emit tessutiTableAdded(tessutoW->toPlainText());
    });
}

//CREA UNA NUOVA RIGA E AGGIUNGE IL WIDGET DI TESTO E UN PULSANTE PER LA ELIMINAZIONE DELLA RIGA NELLA TABELLA TESSUTI (tessutiTable)
void tableView::addItemTessutiTable(unsigned int row,const QString& m){
    //Creo La ADD Row più in basso
    addRowTessutiTable(row+1);

    QTextEdit* tessutoW = new QTextEdit(this);
    tessutoW->setText(m);
    tessutiTable->setCellWidget(row,0,tessutoW);

    connect(tessutoW, &QTextEdit::textChanged,[this,tessutoW]() {
        unsigned int row = tessutiTable->indexAt(tessutoW->pos()).row();
        emit tessutiTableTessutoMod(row,tessutoW->toPlainText());
    });

    //Delete Button Widget
    QPushButton* deleteW = new QPushButton("-",this);

    tessutiTable->setCellWidget(row,1,deleteW);//Widget

    connect(deleteW, &QPushButton::clicked,[this,deleteW]() {
        unsigned int row = tessutiTable->indexAt(deleteW->pos()).row();
        emit tessutiTableRemoved(row);

    });

    emit tessutiTableAddedChecked(m);
}

void tableView::removeItemTessutiTable(unsigned int row){
    tessutiTable->removeRow(row);
    emit tessutiTableRemovedChecked(row);
}


void tableView::modifyItemTessutiTable(unsigned int row, const QString &m){
    QTextEdit* textEdit = static_cast<QTextEdit*>(tessutiTable->cellWidget(row,0));
    textEdit->setText(m);
    emit tessutiTableTessutoModChecked(row,m);
}


