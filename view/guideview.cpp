#include "guideview.h"

GuideView::GuideView(const QSize& s,View* parent): View(s,parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(150,50,150,50);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addLayout(createDescription(tr(
    "Filament3dPrint è un programma che ti può aiutare a tenere\n"
    "traccia delle stampe fatte con una Stampante 3D.\n"
    "Quando si fa una stampa 3D è utile tenere traccia di:\n"
    "- Materiale\n"
    "- Durata\n"
    "- Consumo\n"
    "- Data\n"
    "\n"
    "Il materiale è organizzato in bobine vendute al Kg quindi\n"
    "è utili tenere traccia per ogni stampa quale e quanti grammi\n"
    "di materiale si sono usati.\n"
    "è importante tenere traccia della durata in quanto\n"
    "una stampa 3D può durare svariate ore.\n"
    "\n"
    "Questo programma infine offre dei utili grafici\n"
    "con cui esaminare queste informazioni"),
    ":/3dPrint.jpeg"));


    setLayout(mainLayout);
}

QLayout* GuideView::createDescription(const QString& description, const QString& imgPath){
    //Parte destra immagine e descrizione
    QVBoxLayout* descrLayout = new QVBoxLayout;
    //Immagine stampante descrizione
    QLabel* img = new QLabel(this);
    QPixmap pic = QPixmap(imgPath);
    pic = pic.scaledToHeight(300);
    img->setPixmap(pic);
    img->setFixedSize(300,300);
    descrLayout->addWidget(img,Qt::AlignHCenter);

    //Descrizione
    QLabel* desc = new QLabel(description,this);
    QFont f("Calibri", 9);
    desc->setFont(f);
    descrLayout->addWidget(desc,Qt::AlignJustify);

    return descrLayout;
}
