#include "guideview.h"

GuideView::GuideView(const QSize& s,View* parent): View(s,parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setMargin(0);
    mainLayout->setContentsMargins(150,50,150,50);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->addLayout(createDescription(tr(
    "NomeProg è un programma di supporto per la pianificazione\n"
    "e organizzazione della produzione degli indumenti.\n"
    "Nel processo produttivo, solitamente, la prima fase sta e' \n"
    "quella di pianificare quali tipi di induzmenti verranno \n"
    "prodotti. Da qui si devono prendere in considerazione cosa\n"
    "rodurre (modello), quale tessuto utilizzare,\n"
    "costi per la produzione per esempio:\n"
    "-costo di cucitura\n"
    "-costo del lavaggio\n"
    "-costo del tessuto\n"
    "tempo di impiegato ecc...\n"
    "NomeProg raccoglie tutti questi dati e li mostra con i grafici.\n"),
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
