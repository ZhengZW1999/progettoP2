#include "ctrl.h"
void Ctrl::connectViewCtrlSignalsSlots() const {
    connect(vista,SIGNAL(viewClosed()),this,SLOT(onViewClosed()));
}

Ctrl::Ctrl(View* v, model* m,Ctrl* parent) : QObject(parent), vista(v), modello(m){connectViewCtrlSignalsSlots();}

Ctrl::~Ctrl()
{
    setParent(nullptr);
    for(auto child : children()) delete child;
    delete vista;
    delete modello;
}

void Ctrl::showView() const{vista->show();}

void Ctrl::hideView() const{vista->hide();}
