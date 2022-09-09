#ifndef MODELBARCHART_H
#define MODELBARCHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>
/**
 * @brief La classe modelAreaChart è un Modello relativo al grafico ad barre
 */
class modelBarChart: public model
{
private:
    std::map<std::pair<QString,QString>,std::list<float>> compCostoModello;

    QStringList costiConsiderati;
public:
    explicit modelBarChart(tabelle *t);

    std::map<std::pair<QString,QString>,std::list<float>> getCompCostoModello() const;

    void setCostiConsiderati();

    const QStringList& getCostiConsiderati() const;
};

#endif // MODELBARCHART_H
