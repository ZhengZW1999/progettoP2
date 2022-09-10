#ifndef MODELBARCHART_H
#define MODELBARCHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>

/**
 * @brief La classe modelBarChart è un Modello relativo al grafico ad barre
 */
class modelBarChart: public model
{
private:
    std::map<std::pair<QString,QString>,std::list<double>> compCostoModello;

    QStringList costiConsiderati;
public:

    /**
     * @brief modelBarChart Costruttore del barChart che usa la classe tabelle per
     * costruire un modello di dati che servirà al barchart
     * @param t tabelle
     */
    explicit modelBarChart(tabelle *t);

    /**
     * @brief getCompCostoModello metodo getter per ritornare compCostoModello
     * @return compCostoModello una mappa contenente la lista dei costi che compongono
     * il costo finale della produzione per ogni modello-tessuto
     */
    std::map<std::pair<QString,QString>,std::list<double>> getCompCostoModello() const;

    /**
     * @brief setCostiConsiderati metodo setter per settare i costi in stringhe
     */
    void setCostiConsiderati();

    /**
     * @brief getCostiConsiderati metodo getter per ritornare i costi in stringhe
     * @return costiConsiderati una QstringList contenete i nomi dei costi
     */
    const QStringList& getCostiConsiderati() const;
};

#endif // MODELBARCHART_H
