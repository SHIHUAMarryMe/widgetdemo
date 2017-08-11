#-------------------------------------------------
#
# Project created by QtCreator 2017-08-02T16:38:16
#
#-------------------------------------------------

QT       += core gui
CONFIG   += c++11



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = widgetdemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    button.cpp \
    calculator.cpp \
    listmodel.cpp \
    itemdelegate.cpp

HEADERS  += mainwindow.h \
    utilities.h \
    button.h \
    calculator.h \
    listmodel.h \
    itemdelegate.h

DISTFILES +=

RESOURCES += \
    src.qrc
