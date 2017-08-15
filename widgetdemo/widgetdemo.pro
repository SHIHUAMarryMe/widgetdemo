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
    mainwindow/mainwindow.cpp \
    titlebar/titlebar.cpp \
    centralframe/navigationbar.cpp \
    centralframe/centralframe.cpp \
    centralframe/centralcontentframe.cpp \
    statusbar/statusbar.cpp

HEADERS  += \
    utilities.h \
    mainwindow/mainwindow.h \
    titlebar/titlebar.h \
    centralframe/centralframe.h \
    centralframe/navigationbar.h \
    centralframe/centralcontentframe.h \
    statusbar/statusbar.h

DISTFILES +=

RESOURCES += \
    src.qrc
