QT       += core gui
QT       += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    control/ctrl.cpp \
    control/ctrlareachart.cpp \
    control/ctrlbarchart.cpp \
    control/ctrllinechart.cpp \
    control/ctrlpiechart.cpp \
    control/ctrlstackedbarchart.cpp \
    control/gestionefilejson.cpp \
    control/tablectrl.cpp \
    control/venditectrl.cpp \
    model/datiModelli.cpp \
    model/dativendite.cpp \
    model/modelPiechart.cpp \
    model/modelareaChart.cpp \
    model/modelbarchart.cpp \
    model/modellinechart.cpp \
    model/modelstackedbarchart.cpp \
    model/tabelle.cpp \
    view/areachart.cpp \
    view/barchart.cpp \
    view/guideview.cpp \
    main.cpp \
    mainwindow.cpp \
    model/model.cpp \
    view/linechart.cpp \
    view/piechart.cpp \
    view/stackedbarchart.cpp \
    view/tableview.cpp \
    view/venditeview.cpp \
    view/view.cpp

HEADERS += \
    control/ctrl.h \
    control/ctrlareachart.h \
    control/ctrlbarchart.h \
    control/ctrllinechart.h \
    control/ctrlpiechart.h \
    control/ctrlstackedbarchart.h \
    control/gestionefilejson.h \
    control/tablectrl.h \
    control/venditectrl.h \
    model/datiModelli.h \
    model/dativendite.h \
    model/modelPiechart.h \
    model/modelareaChart.h \
    model/modelbarchart.h \
    model/modellinechart.h \
    model/modelstackedbarchart.h \
    model/tabelle.h \
    view/areachart.h \
    view/barchart.h \
    view/guideview.h \
    mainwindow.h \
    model/model.h \
    view/linechart.h \
    view/piechart.h \
    view/stackedbarchart.h \
    view/tableview.h \
    view/venditeview.h \
    view/view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
