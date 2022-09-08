#ifndef MODELLINECHART_H
#define MODELLINECHART_H

#include "model/model.h"
#include "model/tabelle.h"

#include <map>
#include <QLocale>

class modelLineChart: public model
{
private:
    std::map<QString,std::map<QString,unsigned int>> prodModelliPerTess;
    QStringList* mod;
public:
    explicit modelLineChart(tabelle* t);

    std::map<QString,std::map<QString,unsigned int>> getProdModelliPerTess()const;
    QStringList* getMod(tabelle* t);
};

#endif // MODELLINECHART_H
