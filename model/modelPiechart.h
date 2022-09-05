#ifndef MODELPIECHART_H
#define MODELPIECHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>


class modelPieChart: public model
{
private:
    std::map<std::pair<QString,QString>,std::list<float>> compCostoModello;

    QStringList costiConsiderati;
public:
    explicit modelPieChart(tabelle *t);

    std::map<std::pair<QString,QString>,std::list<float>> getCompCostoModello() const;

    void setCostiConsiderati();

    const QStringList& getCostiConsiderati() const;
};

#endif // MODELPIECHART_H
