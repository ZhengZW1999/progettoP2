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
#include <QCloseEvent>

class venditeView: public View
{
    Q_OBJECT
private:
    QVBoxLayout* venditeLayout;
    QHBoxLayout* venditeBtnLayout;
    QTableWidget* venditeTable;
    QPushButton* areaChartBtn;

    QAction* newProject;
    QAction* saveProject;
    QAction* saveProjectAs;
    QAction* openProject;
    QAction* Exit;

    QAction* AggiungiRiga;

    void connectViewSignals() const override;

protected:
    /**
     * @brief closeEvent Overriding del metodo closeEvent implementato da QWidget
     * Tramite questo Overriding si cerca di modificare il da farsi nel evento di chiusura della window con la X.
     * In particolare questo metodo chiede una conferma al utente prima di chiudere.
     * Viene poi emesso un segnale al controller per avvisarlo della chiusura della finestra.
     * @param event Evento di chiusura della scermata window
     */
    void closeEvent(QCloseEvent* event) override;
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

    void newVenditeProjectPressed() const;
    void openVenditeProjectPressed() const;
    void saveVenditeProjectPressed() const;
    void saveVenditeProjectAsPressed() const;
};

#endif // VENDITEVIEW_H
