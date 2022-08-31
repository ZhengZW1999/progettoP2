#include "modellinechart.h"

void modelLineChart::insertMesi(const QDate &d, QStringList *mesiOrdinati) const
{
    QString meseAnno = QLocale(QLocale::Italian).toString(d,"MMMM yy");
    mesiOrdinati->push_back(meseAnno);
}

modelLineChart::modelLineChart(tabelle *t)
{
    std::list<dati*> listaOrdinata = t->getListaDati();
    listaOrdinata.sort([](dati* a,dati* b) {return a->getData() < b->getData();});

    for(dati* d : listaOrdinata){
        QString meseAnno = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        meseModelloVendite[meseAnno][d->getNomeModello()] += d->getPezziVenduti();
    }

    for(dati* d : listaOrdinata){
        QDate data = d->getData();
        insertMesi(data,&mesiOrdinati);
    }
}
