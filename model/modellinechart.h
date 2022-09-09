#ifndef MODELLINECHART_H
#define MODELLINECHART_H

#include "model/model.h"
#include "model/tabelle.h"

#include <map>
/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico ad linee
 */
class modelLineChart: public model
{
private:
    std::map<QString,std::map<QString,unsigned int>> prodModelliPerTess;
    QStringList mod;
    unsigned int max;
public:
    explicit modelLineChart(tabelle* t);

    std::map<QString,std::map<QString,unsigned int>> getProdModelliPerTess()const;
    const QStringList getMod() const;
    const unsigned int getMax() const;
};

#endif // MODELLINECHART_H
