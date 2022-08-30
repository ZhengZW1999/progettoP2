#ifndef MODELPIECHART_H
#define MODELPIECHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>


class pieChart: public model
{
private:
    std::map<QString,std::list<double>> compCostoModello;
public:
    explicit pieChart(tabelle *t);

    std::map<QString,std::list<double>> getCompCostoModello() const;
};

#endif // MODELPIECHART_H
