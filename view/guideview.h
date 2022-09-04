#ifndef GUIDEVIEW_H
#define GUIDEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "view.h"

class GuideView: public View
{
    Q_OBJECT
private:

    /**
     * @brief createDescriptionLayout
     * Metodo che si occupa di realizzare e predisporre il layout con la parte descrittiva delLa Home
     * @param description descrizione da inserire all'interno del layout
     * @param imgPath path della immagine da includere nel layout
     * @return layout contenente la parte della descrizione della applicazione
     * private perchè invocato solamente nel costruttore
     */
    QLayout* createDescription(const QString& description, const QString& imgPath);
    /**
     * @brief connectViewSignals Metodo virtuale
     * Questo Metodo serve a connettere i SIGNAL degli elementi grafici della Homeview ai SIGNAL della
     * HomeView i quali dovranno comunicare con il Controller HomeCtrl
     */

    //void connectViewSignals() const override;

protected:
    /**
     * @brief closeEvent Overriding del metodo closeEvent implementato da QWidget
     * Tramite questo Overriding si cerca di modificare il da farsi nel evento di chiusura della window con la X.
     * In particolare questo metodo chiede una conferma al utente prima di chiudere.
     * Viene poi emesso un segnale per avvisare il controller della chiusura
     * @param event Evento di chiusura della scermata window
     */
    //void closeEvent(QCloseEvent *event) override;
public:
    /**
     * @brief GuideView
     * Il Costruttore si occupa di Creare la View e creare i due layout laterali della app e mostrarli.
     * @param s Grandezza della finistra, la windowSize
     */
    explicit GuideView(const QSize& s = QSize(),View* parent = nullptr);


public slots:

};

#endif // GUIDEVIEW_H
