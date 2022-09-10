#ifndef MODELPIECHART_H
#define MODELPIECHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>

/**
 * @brief La classe modelPieChart è un Modello relativo al grafico a torta
 */
class modelPieChart: public model
{
private:
    std::map<QString,unsigned int> tessUsatoModello;

public:
    /**
     * @brief modelPieChart Costruttore del pieChart che usa la classe tabelle per
     * costruire un modello di dati che servirà al piechart
     * @param t tabelle
     */
    explicit modelPieChart(tabelle *t);

    /**
     * @brief getTessUsatoModello getter per ritornare tessUsatoModello
     * @return tessUsatoModello una mappa contenente il nunmero di volte del tessuto utilizzato
     */
    std::map<QString,unsigned int> getTessUsatoModello() const;
};

#endif // MODELPIECHART_H
