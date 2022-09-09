#ifndef MODELSTACKEDBARCHART_H
#define MODELSTACKEDBARCHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>
/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico a barre sovrapposte
 */
class modelStackedBarChart: public model
{
private:
    std::map<QString, std::pair<float, float>> rappSpesaGuadagno;
public:
    explicit modelStackedBarChart(tabelle* t);

    std::map<QString, std::pair<float, float>> getRappSpesaGuadagno()const;
};

#endif // MODELSTACKEDBARCHART_H
