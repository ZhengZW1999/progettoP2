#include "modelareaChart.h"

modelAreaChart::modelAreaChart(tabelle *t)
{
    //ordino la lista dei dati secondo la data in ordine crescente
    std::list<datiVendite*> listOrdinata = t->getListaDatiVendite();
    listOrdinata.sort([](datiVendite* a,datiVendite* b) {return a->getData() < b->getData();});

    QString temp= "";
    std::pair<unsigned int,unsigned int> pv(0,0);
    max = 0;
    short int i = 0;
    for(datiVendite* d : listOrdinata){
        //converto la data in stringa nel formato MMMM yy
        QString meseS = QLocale(QLocale::Italian).toString(d->getData(),"MMMM yy");
        //verifico se il mese della lista e' uguale a temp
        if(meseS==temp){
            //sommo i pezzi prodotti e venduti con i pezzi prodotti e venduti della tupla precedente
            pv.first += d->getPezziProdotti();
            pv.second += d->getPezziVenduti();
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
        } else {
            //sovrascrivo la pair con i nuovi dati
            pv = {d->getPezziProdotti(),d->getPezziVenduti()};
            temp = meseS;
            if(max < pv.first || max < pv.second)
                max = pv.first > pv.second ? pv.first : pv.second;
            //la i serve a tenere in ordine dopo nell'inserimento nella map
            i++;
        }
        //siccome quando si inserisce nella map, le chiavi Stringhe vengono ordinate allora si aggiunge un numero davanti alla chiave per
        //tenere in ordine i mesi
        QString iToString = QString::number(i);
        QString mese = iToString+"-"+meseS;

        rappProdVend[mese] = pv;
    }
}

std::map<QString, std::pair<unsigned int, unsigned int> > modelAreaChart::getRappProdVend() const{return rappProdVend;}

const unsigned int modelAreaChart::getMax() const{return max;}
