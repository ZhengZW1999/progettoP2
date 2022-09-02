//#include "mainwindow.h"
#include "view/tablepage.h"

#include <QSize>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    tablePage w;
    w.show();

    return a.exec();

}
