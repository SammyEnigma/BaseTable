#-------------------------------------------------
#
# Project created by QtCreator 2016-11-21T10:29:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseTable
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    basetableitem.cpp \
    basetablewidget.cpp \
    basetabledelegate.cpp

HEADERS  += widget.h \
    basetableitem.h \
    basetablewidget.h \
    basetabledelegate.h
