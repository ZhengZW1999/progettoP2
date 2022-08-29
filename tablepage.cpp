#include "tablepage.h"

tablePage::tablePage(const QSize& s, view* parent): view(s,parent)
{
    createMenu(mainLayout);
}

void tablePage::createMenu(QGridLayout* mainLayout)
{
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);
    QMenu* tabella = new QMenu("Tabella", menuBar);

    menuBar->addMenu(file);
    menuBar->addMenu(tabella);

    file->addAction(new QAction("Salva", file));
    file->addAction(new QAction("Chiudi", file));


    tabella->addAction(new QAction("Aggiungi riga", tabella));
    tabella->addAction(new QAction("Aggiungi colonna", tabella));
    tabella->addAction(new QAction("Elimina riga", tabella));
    tabella->addAction(new QAction("Elimina colonna", tabella));


    mainLayout->addWidget(menuBar);
}

void tablePage::setViewTitle(const QString &title)
{
    setWindowTitle("Progetto "+title);
}

void tablePage::createRecordTable(const QStringList &headers) const
{
    table->setRowCount(0);
    table->setColumnCount(2);
    table->setHorizontalHeaderLabels(headers);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContentsOnFirstShow);
    table->setColumnWidth(4,25);
    mainLayout->addWidget(table,1,0,1,3);
}
