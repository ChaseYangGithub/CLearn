#-------------------------------------------------
#
# Project created by QtCreator 2023-03-14T21:08:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 6_1_QtEvent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mypushbutton.cpp

HEADERS  += widget.h \
    mypushbutton.h

FORMS    += widget.ui

CONFIG+=c++11
