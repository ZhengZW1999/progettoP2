#ifndef DATIVENDITE_H
#define DATIVENDITE_H

#include <QDate>
/**
 * @brief La classe datiVendite è un Modello relativa alla produzione e vendita di un certo mese.
 * Rapresenta il singolo record di memorizzazione della tabella vendite
 */
class datiVendite
{
private:
    unsigned int pezziProdotti;
    unsigned int pezziVenduti;
    QDate data;
public:
    /**
     * @brief datiVendite Costruttore
     * @param pp sono i pezzi prodotti
     * @param pv sono i pezzi venduti
     * @param ds e' la data di riferimento nel formato mese-anno
     */
    explicit datiVendite(unsigned int pp,unsigned int pv, QDate ds);

    unsigned int getPezziProdotti() const;
    unsigned int getPezziVenduti() const;
    const QDate& getData() const;

    void setPezziVenduti(const unsigned int pv){pezziVenduti=pv;}
    void setPezziProdotti(const unsigned int pp){pezziProdotti=pp;}
    void setData(const QDate& d){data=d;}
};

#endif // DATIVENDITE_H
