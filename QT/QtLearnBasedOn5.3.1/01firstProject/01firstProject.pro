#-------------------------------------------------
#
# Project created by QtCreator 2023-02-28T10:30:19
#
#-------------------------------------------------

QT       += core gui#Qt包含的模�?

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets#�?4版本以上包含widgets模块

TARGET = 01firstProject#目标  即生成的exe文件
TEMPLATE = app#模板 应用程序模板 Application


SOURCES += main.cpp\    #源文�?
        mywidget.cpp \
    mypushbutton.cpp

HEADERS  += mywidget.h \#头文�?
    mypushbutton.h
