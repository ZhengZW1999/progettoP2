QT       += core gui
QT       += charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    control/gestionefilejson.cpp \
    model/datiModelli.cpp \
    model/dativendite.cpp \
    model/modelPiechart.cpp \
    model/modelbarchart.cpp \
    model/modellinechart.cpp \
    model/modelposnegbarchart.cpp \
    model/modelstackedbarchart.cpp \
    model/tabelle.cpp \
    view/guideview.cpp \
    view/homeview.cpp \
    main.cpp \
    mainwindow.cpp \
    model/model.cpp \
    view/piechart.cpp \
    view/tablepage.cpp \
    view/venditeview.cpp \
    view/view.cpp

HEADERS += \
    control/gestionefilejson.h \
    model/datiModelli.h \
    model/dativendite.h \
    model/modelPiechart.h \
    model/modelbarchart.h \
    model/modellinechart.h \
    model/modelposnegbarchart.h \
    model/modelstackedbarchart.h \
    model/tabelle.h \
    view/guideview.h \
    view/homeview.h \
    mainwindow.h \
    model/model.h \
    view/piechart.h \
    view/tablepage.h \
    view/venditeview.h \
    view/view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
