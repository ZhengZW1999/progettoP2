#ifndef DATIVENDITE_H
#define DATIVENDITE_H

#include <QDate>

class datiVendite
{
private:
    unsigned int pezziProdotti;
    unsigned int pezziVenduti;
    QDate data;
public:
    explicit datiVendite(unsigned int pp,unsigned int pv, QDate ds);

    unsigned int getPezziProdotti() const;
    unsigned int getPezziVenduti() const;
    const QDate& getData() const;

    void setPezziVenduti(const unsigned int pv){pezziVenduti=pv;}
    void setPezziProdotti(const unsigned int pp){pezziProdotti=pp;}
    void setData(const QDate& d){data=d;}
};

#endif // DATIVENDITE_H
