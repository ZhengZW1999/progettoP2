#include "view.h"

void View::setWindowSize(const QSize & s)
{
    resize(s);
}

void View::setViewTitle(const QString &title)
{
    setWindowTitle(title);
}

View::View(const QSize& s, View* parent): QWidget(parent,Qt::Window)
{
    if(!s.isEmpty() && !s.isNull())
        setWindowSize(s);
}

void View::showCriticalDialog(const QString& title, const QString& mesInfo){
    QMessageBox::critical(this,title,mesInfo,QMessageBox::Ok);
}


