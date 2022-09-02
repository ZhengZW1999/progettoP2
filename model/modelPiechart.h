#ifndef MODELPIECHART_H
#define MODELPIECHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>


class pieChart: public model
{
private:
    std::map<std::pair<QString,QString>,std::list<float>> compCostoModello;
public:
    explicit pieChart(tabelle *t);

    std::map<std::pair<QString,QString>,std::list<float>> getCompCostoModello() const;
};

#endif // MODELPIECHART_H
