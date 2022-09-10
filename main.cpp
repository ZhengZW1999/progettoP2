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

    QCoreApplication::setApplicationName("ProduGrapher");
    a.setWindowIcon(QIcon(":/produGrapherIcon.ico"));

    tableView* tView = new tableView();
    tableCtrl* tCtrl = new tableCtrl(tView);
    tCtrl->showView();
    GuideView* guida = new GuideView();
    guida->show();

    return a.exec();

}
