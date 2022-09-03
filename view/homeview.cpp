#include "homeview.h"

venditeView::venditeView(const QSize& s, View* parent): View(s,parent)
{
    //Creazione Layout
    venditeLayout = new QVBoxLayout;
    venditeBtnLayout = new QHBoxLayout;

    //Creazione Tabella
    venditeTable = new QTableWidget;
    QStringList venditeHeaders = {"Pezzi prodotti", "Pezzi venduti", "Data", ""};
    createVenditeTable(venditeHeaders);

    //Creazione pulsanti
    venditeChartBtn = new QPushButton;

    venditeBtnLayout->addWidget(venditeChartBtn, Qt::AlignCenter);
    venditeLayout->addWidget(venditeTable);
    venditeLayout->addLayout(venditeBtnLayout);

    setLayout(venditeLayout);
}


void venditeView::createVenditeTable(const QStringList& headers) const{
    venditeTable->setRowCount(0);
    venditeTable->setColumnCount(4);
    venditeTable->setHorizontalHeaderLabels(headers);
    venditeTable->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    venditeTable->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
}
