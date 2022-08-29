#include "view.h"

view::view(const QSize& s, view* parent): QWidget(parent,Qt::Window)
{
    if(!s.isEmpty() && !s.isNull())
        setWindowSize(s);
}

void view::setWindowSize(const QSize & s)
{
    resize(s);
}

void view::setViewTitle(const QString &title)
{
    setWindowTitle(title);
}
