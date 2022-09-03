#ifndef VENDITEVIEW_H
#define VENDITEVIEW_H

#include "view/view.h"

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
    QPushButton* venditeChartBtn;

public:
    explicit venditeView(const QSize& s = QSize(), View* parent = nullptr);

    void createVenditeTable(const QStringList& headers) const;

   // void addRowVenditeTable(unsigned int row);

    //void addItemVenditeTable(unsigned int row, unsigned int vendite);

    //void modifyItemVenditeTable(unsigned int row, unsigned int vendite);

    //void removeItemVenditeTable(unsigned int row);
};

#endif // VENDITEVIEW_H
