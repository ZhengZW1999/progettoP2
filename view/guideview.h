#ifndef GUIDEVIEW_H
#define GUIDEVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

#include "tableview.h"

class GuideView: public View
{
    Q_OBJECT
private:


    QLayout* createDescription(const QString& description, const QString& imgPath);

    void connectViewSignals() const override;

public:

    explicit GuideView(const QSize& s = QSize(),View* parent = nullptr);


public slots:

};

#endif // GUIDEVIEW_H
