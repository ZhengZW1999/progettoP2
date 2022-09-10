#include "venditeview.h"

void venditeView::closeEvent(QCloseEvent* event){
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

void venditeView::connectViewSignals() const{
    connect(areaChartBtn,SIGNAL(clicked()),this,SIGNAL(areaChartBPressed()));

    connect(newProject, SIGNAL(triggered()), this, SIGNAL(newVenditeProjectPressed()));
    connect(openProject, SIGNAL(triggered()), this, SIGNAL(openVenditeProjectPressed()));
    connect(saveProject, SIGNAL(triggered()), this, SIGNAL(saveVenditeProjectPressed()));
    connect(saveProjectAs, SIGNAL(triggered()), this, SIGNAL(saveVenditeProjectAsPressed()));

}

venditeView::venditeView(const QSize& s, View* parent): View(s,parent)
{
    //Creazione Layout
    venditeLayout = new QVBoxLayout;
    venditeBtnLayout = new QHBoxLayout;

    venditeLayout->setMargin(0);
    venditeLayout->setSpacing(0);
    venditeBtnLayout->setMargin(20);

    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);
    QMenu* tabella = new QMenu("Tabella", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(tabella);

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

    //MENU TABELLA
    AggiungiRiga = new QAction("Aggiungi Riga", tabella);
    tabella->addAction(AggiungiRiga);


    //Creazione Tabella
    venditeTable = new QTableWidget;

    //Creazione pulsanti
    areaChartBtn = new QPushButton("Rapporto produzione/vendita");
    areaChartBtn->setMaximumWidth(200);

    venditeBtnLayout->addWidget(areaChartBtn, Qt::AlignCenter);
    //venditeBtnLayout->setSpacing(50);

    venditeLayout->addWidget(menuBar);
    venditeLayout->addWidget(venditeTable);
    venditeLayout->addLayout(venditeBtnLayout);


    setLayout(venditeLayout);
    connectViewSignals();
}


void venditeView::createVenditeTable(const QStringList& headers) const{
    venditeTable->setRowCount(0);
    venditeTable->setColumnCount(4);
    venditeTable->setMinimumHeight(200);
    venditeTable->setHorizontalHeaderLabels(headers);
    venditeTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    venditeTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}


void venditeView::addRowVenditeTable(unsigned int row){
    //Inserismo una nuova riga per fare spazio
    venditeTable->insertRow(row);

    QSpinBox* pezziProdottiW = new QSpinBox(this);
    pezziProdottiW->setRange(0,100000);
    pezziProdottiW->setSuffix(" pezzi");
    venditeTable->setCellWidget(row,0,pezziProdottiW);


    //pezziVenduti Widget
    QSpinBox* pezziVendutiW = new QSpinBox(this);
    pezziVendutiW->setRange(0,100000);
    pezziVendutiW->setSuffix(" pezzi");
    venditeTable->setCellWidget(row,1,pezziVendutiW);

    //data Widget
    QDateEdit* dataW = new QDateEdit(this);
    venditeTable->setCellWidget(row,2,dataW);

    //Delete Button Widget
    QPushButton* addW = new QPushButton("+",this);
    venditeTable->setCellWidget(row,3,addW);

    connect(addW, &QPushButton::clicked,this,
            [this, pezziProdottiW, pezziVendutiW, dataW]() {
        if(QDate::currentDate().year() >= dataW->date().year())
            emit venditeTableAdded(pezziProdottiW->value(), pezziVendutiW->value(), dataW->date());
        else
           showCriticalDialog("Inserimento non concesso","La data inserita non e' valida");
    });

}

void venditeView::addItemVenditeTable(unsigned int row,const datiVendite& dv){
    //Creo La ADD Row più in basso
    addRowVenditeTable(row+1);

    //pezziProdotti Widget
    QSpinBox* pezziProdottiW = new QSpinBox(this);
    pezziProdottiW->setRange(0,100000);
    pezziProdottiW->setSuffix(" pezzi");
    pezziProdottiW->setValue(dv.getPezziProdotti());
    venditeTable->setCellWidget(row,0,pezziProdottiW);

    connect(pezziProdottiW, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,[this,pezziProdottiW](int value) {
        unsigned int row = venditeTable->indexAt(pezziProdottiW->pos()).row();
        emit venditeTablePezziProdottiMod(row,value);
        //pezziProdottiW->value() == value
    });

    //pezziVenduti Widget
    QSpinBox* pezziVendutiW = new QSpinBox(this);
    pezziVendutiW->setRange(0,100000);
    pezziVendutiW->setSuffix(" pezzi");
    pezziVendutiW->setValue(dv.getPezziVenduti());
    venditeTable->setCellWidget(row,1,pezziVendutiW);

    connect(pezziVendutiW, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),this,[this,pezziVendutiW](int value) {
        unsigned int row = venditeTable->indexAt(pezziVendutiW->pos()).row();
        emit venditeTablePezziVendutiMod(row,value);
        //pezziVendutiW->value() == value
    });


    //data Widget
    QDateEdit* dataW = new QDateEdit(dv.getData(),this);
    venditeTable->setCellWidget(row,2,dataW);

    connect(dataW, &QDateEdit::dateChanged,this,[this,dataW](const QDate& data) {
        unsigned int row = venditeTable->indexAt(dataW->pos()).row();
        emit venditeTableDataMod(row,data);
        //dataW->date() == data
    });

    //Delete Button Widget
    QPushButton* deleteW = new QPushButton("-",this);
    venditeTable->setCellWidget(row,3,deleteW);//Widget

    //Connessione al pulsante delete per eliminare la riga e aggiornare il modello di dati con l'eliminazione
    connect(deleteW, &QPushButton::clicked,this,[this,deleteW]() {
        unsigned int row = venditeTable->indexAt(deleteW->pos()).row();
        emit venditeTableRemoved(row);
        venditeTable->removeRow(row);
    });
}
