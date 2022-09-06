#include "piechart.h"

pieChart::pieChart(const QSize &s, View *parent,const QStringList *lista): View(s,parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout;
    chart->addSeries(series);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTheme(QChart::ChartThemeLight);
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(1500);
    QChartView *chartView = new QChartView(chart,this);
    chartView->setRenderHint(QPainter::Antialiasing);
    listBox=createChartListBox(lista);
    mainLayout->addWidget(new QLabel("Modello: "));
    mainLayout->addWidget(listBox);
    mainLayout->addWidget(chartView);
    setLayout(mainLayout);
    setMinimumSize(800,500);
    resize(s);
}

void pieChart::insertDati(const QString &tipoCosto, float costo)
{
    series->append(tipoCosto, costo);
}

void pieChart::viewSetting()
{
    for(QPieSlice* slice : series->slices()){
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setLabelColor(Qt::green);
    }
    chart->setTitle("Costo finale per produzione");
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);
}

/*void pieChart::connectViewSignals() const{
    connect(listBox,static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,SIGNAL(indexChanged()));
}
*/
QComboBox *pieChart::createChartListBox(const QStringList* lista) const
{
    QComboBox *list = new QComboBox();
    for(const QString& a : *lista){
        list->addItem(a, a);
    }
    return list;
}
