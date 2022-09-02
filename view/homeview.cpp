#include "homeview.h"

HomeView::HomeView(const QSize& s,View* parent): View(s,parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->setSpacing(10);
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(150,50,150,50);
    mainLayout->setAlignment(Qt::AlignCenter);

    nuovo = new QPushButton("Nuovo",this);
    carica = new QPushButton("Apri esistente",this);
    nuovo->setFixedSize(150,70);
    carica->setFixedSize(150,70);

    mainLayout->addWidget(nuovo);
    mainLayout->addWidget(carica);

    resize(QSize(800, 600));

    setLayout(mainLayout);
}
