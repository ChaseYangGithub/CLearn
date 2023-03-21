#-------------------------------------------------
#
# Project created by QtCreator 2023-03-02T23:10:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    teacher.cpp \
    student.cpp

HEADERS  += widget.h \
    teacher.h \
    student.h

FORMS    += widget.ui

CONFIG+=c++11
