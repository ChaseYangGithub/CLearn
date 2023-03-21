#-------------------------------------------------
#
# Project created by QtCreator 2023-03-14T17:38:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 5_7_5_CustomControlPackaging
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    smallwidget.cpp

HEADERS  += widget.h \
    smallwidget.h

FORMS    += widget.ui \
    smallwidget.ui
CONFIG+=c++11
