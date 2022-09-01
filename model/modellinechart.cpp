#include "modellinechart.h"

void modelLineChart::insertMesi(const QDate &d, QStringList *mesiOrdinati) const
{
    QString meseAnno = QLocale(QLocale::Italian).toString(d,"MMMM yy");
    mesiOrdinati->push_back(meseAnno);
}

modelLineChart::modelLineChart(tabelle *t)
{
    std::list<datiModelli*> listaOrdinata = t->getListaDatiModelli();
    listaOrdinata.sort([](datiModelli* a,datiModelli* b) {return a->getData() < b->getData();});

    for(datiModelli* d : listaOrdinata){
        QString meseAnno = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        meseModelloVendite[meseAnno][d->getNomeModello()] += d->getPezziVenduti();
    }

    for(datiModelli* d : listaOrdinata){
        QDate data = d->getData();
        insertMesi(data,&mesiOrdinati);
    }
}

std::map<QString, std::map<QString, unsigned int> > modelLineChart::getMeseModelloVendite() const{}
