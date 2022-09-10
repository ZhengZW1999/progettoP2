#ifndef MODELSTACKEDBARCHART_H
#define MODELSTACKEDBARCHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>
/**
 * @brief La classe modelStackedBarChart è un Modello relativo al grafico a barre sovrapposte
 */
class modelStackedBarChart: public model
{
private:
    std::map<QString, std::pair<float, float>> rappSpesaGuadagno;
public:
    /**
     * @brief modelStackedBarChart Costruttore del bar Chart sovrapposte che usa la classe tabelle per
     * costruire un modello di dati che servirà al bar Chart sovrapposte
     * @param t tabelle
     */
    explicit modelStackedBarChart(tabelle* t);

    /**
     * @brief getRappSpesaGuadagno getter per ritornare rappSpesaGuadagno
     * @return rappSpesaGuadagno una mappa contenente la spesa per la produzione e il guadagno di
     * un certo modello
     */
    std::map<QString, std::pair<float, float>> getRappSpesaGuadagno()const;
};

#endif // MODELSTACKEDBARCHART_H
