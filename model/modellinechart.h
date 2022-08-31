#ifndef MODELLINECHART_H
#define MODELLINECHART_H

#include "model/model.h"
#include "model/tabelle.h"

#include <list>
#include <map>
#include <QLocale>

class modelLineChart: public model
{
private:
    std::map<QString,std::map<QString,unsigned int>> meseModelloVendite;

    QStringList mesiOrdinati;

    void insertMesi(const QDate& d, QStringList* mesiOrdinati) const;
public:
    explicit modelLineChart(tabelle* t);

    std::map<QString,std::map<QString,unsigned int>> getMeseModelloVendite()const;

    const QStringList& getMesiOrdinati() const;
};

#endif // MODELLINECHART_H
