#ifndef TABLECTRL_H
#define TABLECTRL_H

#include "control/ctrl.h"
#include "control/ctrlbarchart.h"
#include "control/ctrllinechart.h"
#include "control/ctrlstackedbarchart.h"
#include "control/ctrlpiechart.h"
#include "control/venditectrl.h"

#include "view/tableview.h"
#include "view/barchart.h"
#include "view/linechart.h"
#include "view/stackedbarchart.h"
#include "view/piechart.h"

#include "view/guideview.h"
#include "view/venditeview.h"


#include "model/tabelle.h"
#include "model/modelbarchart.h"
#include "model/modellinechart.h"
#include "model/modelstackedbarchart.h"
#include "model/modelPiechart.h"


#include <list>

class tableCtrl: public Ctrl
{
    Q_OBJECT
private:

    void connectViewCtrlSignalsSlots() const;

public:
    /**
     * @brief AdminCtrl
     * @param v View collegata al Controller
     * @param m Model collegato al Controller
     */
    tableCtrl(tableView* v, tabelle* m = new tabelle(), Ctrl* parent = nullptr);

    /**
     * @brief getView Ritorna La View castata almeno al tipo corrente AdminView
     * @return
     */
    tableView* getView() const override;

    /**
     * @brief getModel Ritorna il Model castato almeno al tipo corrente ModelView
     * @return
     */
    tabelle* getModel() const override;

signals:

public slots:
    /**
     * @brief onViewClosed SLOT eseguito alla ricezione di SEGNALI di chiusura della View
     * In questo caso distrugger il suddetto controller, che di seguito distrugge la view e il model
     */
    void onViewClosed() const override;

     void onDataTableRemoved(unsigned int row);

     void onDataTableAdded(const QString& m, const QString& t, double tU, double cT, double cB, double cL, double cV, unsigned int pG);

     void onDataTableModelloMod(unsigned int row,const QString& m);

     void onDataTableTessutoMod(unsigned int row,const QString& t);


     void onModelliTableAdded(const QString& m);

     void onModelliTableModelloMod(unsigned int row,const QString& m);

     void onModelliTableRemoved(unsigned int row);


     void onTessutiTableAdded(const QString& t);

     void onTessutiTableTessutoMod(unsigned int row,const QString& t);

     void onTessutiTableRemoved(unsigned int row);


     void onDataTableTessUsatoMod(unsigned int row, double tu);

     void onDataTableCostoTessutoMod(unsigned int row, double ct);

     void onDataTableCostoBaseMod(unsigned int row, double cb);

     void onDataTableCostoLavaggioMod(unsigned int row, double cl);

     void onDataTableCostoVenditaMod(unsigned int row, double cv);

     void onDataTableProdGiornalieraMod(unsigned int row, unsigned int pd);


     void onPieChartBPressed()const;

     void onLineChartBPressed()const;

     void onBarChartBPressed() const;

     void onStackedBarChartBPressed() const;


     void onVenditePressed() const;

     void onGuidePressed() const;


     void onNewProjectPressed() const;

     void onOpenProjectPressed() const;

     void onSaveProjectPressed() const;

     void onSaveProjectAsPressed() const;

};

#endif // TABLECTRL_H
