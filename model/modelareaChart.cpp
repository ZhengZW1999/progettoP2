#include "modelareaChart.h"

modelAreaChart::modelAreaChart(tabelle *t)
{
    //ordino la lista dei dati secondo la data in ordine crescente
    std::list<datiVendite*> listOrdinata = t->getListaDatiVendite();
    listOrdinata.sort([](datiVendite* a,datiVendite* b) {return a->getData() < b->getData();});

    QString temp= "";
    std::pair<unsigned int,unsigned int> pv(0,0);
    max = 0;
    for(datiVendite* d : listOrdinata){
        //converto la data in stringa nel formato MM yyyy
        QString mese = QLocale(QLocale::Italian).toString(d->getData(),"yyyy MM");
        //verifico se il mese della lista e' uguale a temp
        if(mese==temp){
            //sommo i pezzi prodotti e venduti con i pezzi prodotti e venduti della tupla precedente
            pv.first += d->getPezziProdotti();
            pv.second += d->getPezziVenduti();
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
        } else {
            //sovrascrivo la pair con i nuovi dati
            pv = {d->getPezziProdotti(),d->getPezziVenduti()};
            temp = mese;
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
        }
        rappProdVend[mese] = pv;
    }
}

std::map<QString, std::pair<unsigned int, unsigned int> > modelAreaChart::getRappProdVend() const{return rappProdVend;}

const unsigned int modelAreaChart::getMax() const{return max;}
