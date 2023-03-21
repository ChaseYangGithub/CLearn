#-------------------------------------------------
#
# Project created by QtCreator 2023-03-16T17:16:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 9_TurnOverGame
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbutton.cpp \
    chooselevelscene.cpp \
    gamescene.cpp \
    myimage.cpp \
    dataconfig.cpp

HEADERS  += mainscene.h \
    mypushbutton.h \
    chooselevelscene.h \
    myimage.h \
    gamescene.h \
    dataconfig.h

FORMS    += mainscene.ui

RESOURCES += \
    res.qrc \
    res2.qrc
#c++11
CONFIG+=c++11
CONFIG+=resources_big
QT += multimedia#QSound需要

