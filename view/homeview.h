#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "view.h"

class HomeView: public view
{
    Q_OBJECT
private:

    QPushButton* nuovo;
    QPushButton* carica;

public:
    explicit HomeView(const QSize& s = QSize(),view* parent = nullptr);

};

#endif // HOMEVIEW_H
