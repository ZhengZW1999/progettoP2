#ifndef MODELLINECHART_H
#define MODELLINECHART_H

#include "model/model.h"
#include "model/tabelle.h"

#include <map>

/**
 * @brief La classe modelLineChart è un Modello relativo al grafico ad linee
 */
class modelLineChart: public model
{
private:
    std::map<QString,std::map<QString,unsigned int>> prodModelliPerTess;
    QStringList mod;
    unsigned int max;
public:

    /**
     * @brief modelLineChart Costruttore del lineChart che usa la classe tabelle per
     * costruire un modello di dati che servirà al linechart
     * @param t tabelle
     */
    explicit modelLineChart(tabelle* t);

    /**
     * @brief getProdModelliPerTess metodo getter per ritornare prodModelliPerTess
     * @return prodModelliPerTess una mappa contenente i dati relativi alla produzione giornaliera
     * di tutti i modello divisi per tessutti diversi
     */
    std::map<QString,std::map<QString,unsigned int>> getProdModelliPerTess()const;

    /**
     * @brief getMod metodo getter getter per ritornare mod
     * @return mod una QStringList contenente la lista dei modelli
     */
    const QStringList getMod() const;

    /**
     * @brief getMax metodo getter getter per ritornare max
     * @return max il massimo valore verificato della produzione giornaliera
     */
    const unsigned int getMax() const;
};

#endif // MODELLINECHART_H
