//#include "mainwindow.h"
#include "view/view.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    view h;
    h.show();
    return a.exec();
}
