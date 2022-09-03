//#include "mainwindow.h"
#include "view/tablepage.h"
#include "view/guideview.h"
#include "view/homeview.h"

#include <QSize>
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    tablePage w;
    //HomeView w;
    w.show();

    return a.exec();

}
