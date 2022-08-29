#ifndef TABLEPAGE_H
#define TABLEPAGE_H

#include <QWidget>
#include <QSize>
#include <QMessageBox>
#include <QTableWidget>
#include <QGridLayout>
#include <QMenuBar>

#include "view.h"

class tablePage: public view
{
    Q_OBJECT
private:
    QGridLayout* mainLayout;
    QTableWidget* table;
    QPushButton* addRow;
    QPushButton* addColumn;
    QPushButton* saveB;
    QPushButton* saveAsB;
public:
    explicit tablePage(const QSize& s = QSize(), view* parent = nullptr);

    void createMenu(QGridLayout* mainLayout);

    void setViewTitle (const QString &title) override;

    void createRecordTable(const QStringList& headers) const;
};

#endif // TABLEPAGE_H
