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
    QStringList mod;

    void setMod(const QString &s);
public:
    explicit modelLineChart(tabelle* t);

    std::map<QString,std::map<QString,unsigned int>> getProdModelliPerTess()const;
    const QStringList getMod() const;
};

#endif // MODELLINECHART_H
