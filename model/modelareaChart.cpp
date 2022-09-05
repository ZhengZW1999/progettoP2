#include "modelareaChart.h"

modelAreaChart::modelAreaChart(tabelle *t)
{
    std::list<datiVendite*> listOrdinata = t->getListaDatiVendite();
    listOrdinata.sort([](datiVendite* a,datiVendite* b) {return a->getData() < b->getData();});

    QString temp= "";
    std::pair<unsigned int,unsigned int> pv(0,0);
    for(datiVendite* d : listOrdinata){
        QString mese = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        if(mese==temp){
            pv.first += d->getPezziProdotti();
            pv.second += d->getPezziVenduti();
        } else {
            pv = {d->getPezziProdotti(),d->getPezziVenduti()};
            temp = mese;
        }

        rappProdVend.insert({mese,pv});
    }
}

std::map<QString, std::pair<unsigned int, unsigned int> > modelAreaChart::getRappProdVend() const{return rappProdVend;}
