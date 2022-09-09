#include "modelareaChart.h"

modelAreaChart::modelAreaChart(tabelle *t)
{
    std::list<datiVendite*> listOrdinata = t->getListaDatiVendite();
    listOrdinata.sort([](datiVendite* a,datiVendite* b) {return a->getData() < b->getData();});

    QString temp= "";
    std::pair<unsigned int,unsigned int> pv(0,0);
    max = 0;
    for(datiVendite* d : listOrdinata){
        QString mese = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        if(mese==temp){
            pv.first += d->getPezziProdotti();
            pv.second += d->getPezziVenduti();
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
        } else {
            pv = {d->getPezziProdotti(),d->getPezziVenduti()};
            temp = mese;
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
        }

        rappProdVend.insert({mese,pv});
    }
}

std::map<QString, std::pair<unsigned int, unsigned int> > modelAreaChart::getRappProdVend() const{return rappProdVend;}

const unsigned int modelAreaChart::getMax() const{return max;}
