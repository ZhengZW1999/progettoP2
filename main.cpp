#include "mainwindow.h"
#include "view/homeview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    HomeView h;
    h.show();
    return a.exec();
}
