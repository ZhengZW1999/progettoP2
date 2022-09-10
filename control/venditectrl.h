#ifndef VENDITECTRL_H
#define VENDITECTRL_H

#include "control/ctrl.h"
#include "control/ctrlareachart.h"

#include "control/tablectrl.h"
#include "view/tableview.h"
#include "view/venditeview.h"

#include "model/tabelle.h"
#include "model/modelareaChart.h"


#include <list>

class venditeCtrl: public Ctrl
{
     Q_OBJECT

private:

    void connectViewCtrlSignalsSlots() const;

public:

     venditeCtrl(venditeView* v, tabelle* m = new tabelle(), Ctrl* parent = nullptr);

     venditeView* getView() const override;

     tabelle* getModel() const override;


signals:

public slots:    
     /**
      * @brief onViewClosed SLOT eseguito alla ricezione di SEGNALI di chiusura della View
      * In questo caso distrugger il suddetto controller, che di seguito distrugge la view e il model
      */
     void onViewClosed() const override;

     void onVenditeTableAdded(unsigned int pP, unsigned int pV, QDate data);
     void onVenditeTableRemoved(unsigned int row);
     void onVenditeTablePezziProdottiMod(unsigned int row, unsigned int pP);
     void onVenditeTablePezziVendutiMod(unsigned int row, unsigned int pV);
     void onVenditeTableDataMod(unsigned int row, QDate data);

     void onAreaChartBPressed() const;


};

#endif // VENDITECTRL_H
