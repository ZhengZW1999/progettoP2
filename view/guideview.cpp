#include "guideview.h"


void GuideView::connectViewSignals() const{

}

GuideView::GuideView(const QSize& s,View* parent): View(s,parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(50,15,50,15);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addLayout(createDescription(tr(
    "ProduGrapher è un programma di supporto per la pianificazione e organizzazione della\n"
    "produzione degli indumenti. Nel processo produttivo, solitamente, la prima fase sta e'\n"
    "quella di pianificare quali tipi di indumenti verranno prodotti.\n"
    "Da qui si devono prendere in considerazione cosa produrre (modello),\n"
    " quale tessuto utilizzare, costi per la produzione\n"
    "per esempio:\n"
    "- costo di cucitura\n"
    "- costo del lavaggio\n"
    "- costo del tessuto\n"
    "tempo di impiegato ecc...\n"      
    "ProduGrapher raccoglie tutti questi dati e li mostra con i grafici.\n\n"
    "Guida Utente \n\n"
    "- Modello si puo' intende il tipo di indumento in generale(felpa,pantaloni,magliette)\n"
    "- Tessuto si intende il tessuto che si vuole usare per il modello\n"
    "- Tessuto usato per MQ e' la quantita' di tessuto necessario per pruduzione di un singolo capo\n"
    "- Costo tessuto per MQ si intente il costo del tessuto\n"
    "- Costo base sono tutti gli altri costi necessari nella fase di produzione (taglio tessuto, cucitura, trasporto)\n"
    "- Costo Lavaggio e' il costo del lavaggio dei capi prima che vengano messi in vendita\n"
    "- Prezzo Vendita si intende il prezzo che si intende fissare per la vendita\n"
    "- Produzione giornaliera si intende il numero di capi prodotti in una giornata in media\n"
    "Il programma inoltre da anche la possibilita' di inserire dati relativi alla produzione e vendita totalle mensile\n"
    "cosi da visualizzarlo in grafico. E' utile in quanto vedendo l'andamento delle vendite dei mesi precedenti\n"
    "aiuta a pianificare il numero di capi da produrre nelle prossime stagioni\n"),
    ":/produGrapher.png"));


    setLayout(mainLayout);
}

QLayout* GuideView::createDescription(const QString& description, const QString& imgPath){
    //Parte destra immagine e descrizione
    QVBoxLayout* descrLayout = new QVBoxLayout;

    QLabel* img = new QLabel(this);
    QPixmap pic = QPixmap(imgPath);
    img->setPixmap(pic);
    img->resize(400,85);
    img->setAlignment(Qt::AlignCenter);
    img->setMargin(25);
    descrLayout->addWidget(img,Qt::AlignHCenter);

    //Descrizione
    QLabel* desc = new QLabel(description,this);
    QFont f("Calibri", 10);
    desc->setFont(f);
    descrLayout->addWidget(desc,Qt::AlignJustify);

    return descrLayout;
}
/*Guida Utente
 *  -Modello si puo' intende il tipo di indumento in generale(felpa,pantaloni,magliette)
 *      oppure il modello specifico di un vestito
 *  -Tessuto si intente il tessuto che si vuole usare per il modello
 *  -Tessuto usaato per MQ e' la quantita' di tessuto necessario per pruduzione di un singolo capo
 *  -Costo tessuto per MQ si intente il costo del tessuto
 *  -Costo base sono tutti gli altri costi necessari nella fase di produzione (taglio tessuto, cucitura, trasporto)
 *  -Costo Lavaggio e' il costo del lavaggio dei capi prima che vengano messi in vendita
 *  -Prezzo Vendita si intende il prezzo che si intende fissare per la vendita
 *  -Produzione giornaliera si intende il numero di capi prodotti in una giornata in media
 *
 *Il programma inoltre da anche la possibilita' di inserire dati relativi alla produzione e vendita totalle mensile
 *cosi da visualizzarlo in grafico. E' utile in quanto vedendo l'andamento delle vendite dei mesi precedenti
 *aiuta a pianificare il numero di capi da produrre nelle prossime stagioni
*/
