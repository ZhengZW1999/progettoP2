//#include "mainwindow.h"
#include "view/tableview.h"
#include "control/tablectrl.h"
#include "view/venditeview.h"


#include <QSize>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    //MainWindow w;
    venditeView h;
    //HomeView w;
    h.show();
    */
    //GuideView h;
    tableView* tView = new tableView();
    tableCtrl* tCtrl = new tableCtrl(tView);
    tCtrl->showView();

    return a.exec();

}
