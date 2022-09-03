#ifndef GUIDEVIEW_H
#define GUIDEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "view.h"

class guideView: public View
{
    Q_OBJECT
private:
    QPushButton* nuovo;
    QPushButton* carica;

public:
    explicit guideView(const QSize& s = QSize(),View* parent = nullptr);

};

#endif // GUIDEVIEW_H
