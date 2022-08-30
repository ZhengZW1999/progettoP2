#ifndef MODELBARCHART_H
#define MODELBARCHART_H

#include "model/model.h"
#include "model/tabelle.h"
#include <map>

class modelBarChart: public model
{
private:
    std::map<QString,unsigned int> tessUsatoModello;

public:
    explicit modelBarChart(tabelle *t);

    std::map<QString,unsigned int> getTessUsatoModello() const;
};

#endif // MODELBARCHART_H
