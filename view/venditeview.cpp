#include "venditeview.h"

venditeView::venditeView(const QSize& s, View* parent): View(s,parent)
{
    //Creazione Layout
    venditeLayout = new QVBoxLayout;
    venditeBtnLayout = new QHBoxLayout;

    venditeLayout->setMargin(0);
    venditeLayout->setSpacing(0);
    venditeBtnLayout->setMargin(20);

    //Menu
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* tabella = new QMenu("Tabella", menuBar);

    tabella->addAction(new QAction("Inserisci Riga"));
    tabella->addAction(new QAction("Elimina Riga"));
    menuBar->addMenu(tabella);


    //Creazione Tabella
    venditeTable = new QTableWidget;
    QStringList venditeHeaders = {"Pezzi prodotti", "Pezzi venduti", "Data", ""};
    createVenditeTable(venditeHeaders);

    //Creazione pulsanti
    venditeChartBtn = new QPushButton("Rapporto produzione/vendita");
    pageViewBtn = new QPushButton("Indietro");
    pageViewBtn->setMaximumWidth(75);
    venditeChartBtn->setMaximumWidth(200);

    venditeBtnLayout->addWidget(pageViewBtn, Qt::AlignLeft);
    venditeBtnLayout->addWidget(venditeChartBtn, Qt::AlignRight);
    //venditeBtnLayout->setSpacing(50);

    venditeLayout->addWidget(menuBar);
    venditeLayout->addWidget(venditeTable);
    venditeLayout->addLayout(venditeBtnLayout);


    setLayout(venditeLayout);
}


void venditeView::createVenditeTable(const QStringList& headers) const{
    venditeTable->setRowCount(0);
    venditeTable->setColumnCount(4);
    venditeTable->setMinimumHeight(200);
    venditeTable->setHorizontalHeaderLabels(headers);
    venditeTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    venditeTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}
