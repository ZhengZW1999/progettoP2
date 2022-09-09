#ifndef VENDITEVIEW_H
#define VENDITEVIEW_H

#include "view/view.h"


#include <QMenuBar>
#include <QMenu>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpinBox>
#include <QDateEdit>
#include <QPushButton>

class venditeView: public View
{
    Q_OBJECT
private:
    QVBoxLayout* venditeLayout;
    QHBoxLayout* venditeBtnLayout;
    QTableWidget* venditeTable;
    QPushButton* areaChartBtn;
    QPushButton* pageViewBtn;

    void connectViewSignals() const override;


public:
    explicit venditeView(const QSize& s = QSize(), View* parent = nullptr);

    void createVenditeTable(const QStringList& headers) const;
    void addRowVenditeTable(unsigned int row);
    void addItemVenditeTable(unsigned int row, const datiVendite& dv);

signals:
    void venditeTableAdded(uint, uint, QDate) const;
    void venditeTableRemoved(uint);
    void venditeTablePezziProdottiMod(uint, uint) const;
    void venditeTablePezziVendutiMod(uint, uint) const;
    void venditeTableDataMod(uint, QDate) const;
    void areaChartBPressed() const;
};

#endif // VENDITEVIEW_H
