#ifndef PIECHART_H
#define PIECHART_H

#include "view.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QHBoxLayout>
#include <QComboBox>
#include <QStringList>
#include <QLabel>

QT_CHARTS_USE_NAMESPACE

class pieChart: public View
{
private:
    void connectViewSignals() const ;
protected:
    QPieSeries *series;
    QChart *chart;
    QStringList *listaModelli;
    QComboBox *listBox;
    QComboBox *createChartListBox(const QStringList* lista) const;
public:
    explicit pieChart(const QSize& s = QSize(800,500),View* parent = nullptr,const QStringList *lista = nullptr);

    void insertDati(const QString& tipoCosto, float costo);

    void viewSetting();

signals:
    void listBoxPressed() const;

};

#endif // PIECHART_H
