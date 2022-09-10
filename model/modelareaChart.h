#ifndef MODELAREACHART_H
#define MODELAREACHART_H

#include <QLocale>
#include "model/model.h"
#include "model/tabelle.h"
#include <map>
#include <qdebug.h>

/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico ad area
 */
class modelAreaChart: public model
{
private:
    std::map<QString,std::pair<unsigned int,unsigned int>> rappProdVend;
    unsigned int max;
public:

    /**
     * @brief modelAreaChart Costruttore del areaChart che usa la classe tabelle per
     * costruire un modello di dati che servirà al areachart
     * @param t tabelle
     */
    explicit modelAreaChart(tabelle* t);

    /**
     * @brief getRappProdVend getter per ritornare rappProdVend
     * @return rappProdVend una mappa contenente una coppia di valori pezzi prodotti, pezzi venduti
     * per ogni mese
     */
    std::map<QString,std::pair<unsigned int,unsigned int>> getRappProdVend()const;

    /**
     * @brief getMax getter per ritornare max
     * @return max valore massimo tra tutti i pezzi prodotti/venduti
     * che serve a costruire nella view l'asse Y
     */
    const unsigned int getMax() const;
};

#endif // MODELAREACHART_H
