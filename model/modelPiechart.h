#ifndef MODELPIECHART_H
#define MODELPIECHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>

/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico a torta
 */
class modelPieChart: public model
{
private:
    std::map<QString,unsigned int> tessUsatoModello;

public:
    explicit modelPieChart(tabelle *t);

    std::map<QString,unsigned int> getTessUsatoModello() const;
};

#endif // MODELPIECHART_H
