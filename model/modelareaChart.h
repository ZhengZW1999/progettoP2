#ifndef MODELAREACHART_H
#define MODELAREACHART_H

#include <QLocale>
#include "model/model.h"
#include "model/tabelle.h"
#include <map>
/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico ad area
 */
class modelAreaChart: public model
{
private:
    std::map<QString,std::pair<unsigned int,unsigned int>> rappProdVend;

public:
    /**
     * @brief La classe modelAreaChart è un Modello relativo al grafico ad area
     */
    explicit modelAreaChart(tabelle* t);
    std::map<QString,std::pair<unsigned int,unsigned int>> getRappProdVend()const;

};

#endif // MODELAREACHART_H
