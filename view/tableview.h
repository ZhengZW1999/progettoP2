#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include "view/view.h"

#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QCloseEvent>
#include <QHeaderView>


class tableView: public View
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;

    QTableWidget* dataTable;
    QTableWidget* modelliTable;
    QTableWidget* tessutiTable;

    QPushButton* pieChartBtn;
    QPushButton* barChartBtn;
    QPushButton* lineChartBtn;
    QPushButton* stackedBarChartBtn;
    QPushButton* venditeBtn;
    QPushButton* guida;

    QAction* newProject;
    QAction* saveProject;
    QAction* saveProjectAs;
    QAction* openProject;
    QAction* Exit;

    void connectViewSignals() const override;
protected:

    void closeEvent(QCloseEvent* event) override;

public:
    explicit tableView(const QSize& s = QSize(), View* parent = nullptr);

    //TABELLA DATI
     void createDataTable(const QStringList& headers) const;

    void addRowDataTable(unsigned int row, const QStringList& listaModelli, const QStringList& listaTessuti);

    void addItemDataTable(unsigned int row,const datiModelli& d, const QStringList& listaModelli, const QStringList& listaTessuti );


    //MODELLI e TESSUTI TABLE
    void createModelliTable(const QStringList& headers) const;

    void addRowModelliTable(unsigned int row);

    void addItemModelliTable(unsigned int row, const QString& m);

    void createTessutiTable(const QStringList& headers) const;

    void addRowTessutiTable(unsigned int row);

    void addItemTessutiTable(unsigned int row, const QString& m);

    void modifyItemModelliTable(unsigned int row, const QString& m);

    void removeItemModelliTable(unsigned int row);

    void modifyItemTessutiTable(unsigned int row, const QString& m);

    void removeItemTessutiTable(unsigned int row);


signals:
    //SIGNAL catturatti da un Controller, servono per aggiornare il Model con la modifica della dataTable
    void dataTableRemoved(uint) const;
    void dataTableAdded(QString, QString, float, float, float, float, float, uint) const;

    void dataTableModelloMod(uint, QString) const;
    void dataTableTessutoMod(uint, QString) const;
    void dataTableTessUsatoMod(uint, float) const;
    void dataTableCostoTessutoMod(uint, float) const;
    void dataTableCostoBaseMod(uint, float) const;
    void dataTableCostoLavaggioMod(uint, float) const;
    void dataTableCostoVenditaMod(uint, float) const;
    void dataTableProdGiornalieraMod(uint, uint) const;

    //SIGNAL catturati da un Controller, servono per aggiornare il Model con la modifica delle modelliTable e tessutiTable
    void modelliTableAdded(QString) const;
    void modelliTableModelloMod(uint,QString) const;
    void modelliTableRemoved(uint) const;

    void tessutiTableAdded(QString) const;
    void tessutiTableTessutoMod(uint,QString) const;
    void tessutiTableRemoved(uint) const;

    //SIGNAL catturati dalla View, servono per aggiornare i QComboBox con la modifica dei campo dati Modello e Tessuto della dataTable
    void modelliTableAddedChecked(QString) const;
    void modelliTableRemovedChecked(uint) const;
    void modelliTableModelloModChecked(uint,QString) const;

    void tessutiTableAddedChecked(QString) const;
    void tessutiTableRemovedChecked(uint) const;
    void tessutiTableTessutoModChecked(uint,QString) const;

    void barChartBPressed() const;
    void stackedBarChartBPressed() const;
    void lineChartBPressed() const;
    void pieChartBPressed() const;

    void venditePressed() const;
    void guidePressed() const;   

    void newProjectPressed() const;
    void openProjectPressed() const;
    void saveProjectPressed() const;
    void saveProjectAsPressed() const;
};


#endif // TABLEVIEW_H
