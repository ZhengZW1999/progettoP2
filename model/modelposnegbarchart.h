#ifndef MODELPOSNEGBARCHART_H
#define MODELPOSNEGBARCHART_H

#include <QLocale>
#include "model/model.h"
#include "model/tabelle.h"
#include <map>

class modelPosNegBarChart: public model
{
private:
    std::map<QString,std::pair<unsigned int,unsigned int>> rappProdVend;
public:
    explicit modelPosNegBarChart(tabelle* t);
    std::map<QString,std::pair<unsigned int,unsigned int>> getRappProdVend()const;
};

#endif // MODELPOSNEGBARCHART_H
