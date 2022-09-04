#include "modelareaChart.h"

modelAreaChart::modelAreaChart(tabelle *t)
{
    std::list<datiVendite*> listOrdinata = t->getListaDatiVendite();
    listOrdinata.sort([](datiVendite* a,datiVendite* b) {return a->getData() < b->getData();});

    for(datiVendite* d : listOrdinata){
        QString mese = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        std::pair<unsigned int,unsigned int> pv = {d->getPezziProdotti(),d->getPezziVenduti()};
        rappProdVend.insert({mese,pv});
    }
}

std::map<QString, std::pair<unsigned int, unsigned int> > modelAreaChart::getRappProdVend() const{return rappProdVend;}
