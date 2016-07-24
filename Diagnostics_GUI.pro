#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T08:40:11
#
#-------------------------------------------------

QT       += core gui
QT += network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diagnostics_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    receiver.cpp

HEADERS  += mainwindow.h \
    helper.h \
    receiver.h

FORMS    += mainwindow.ui

CONFIG += mobility
MOBILITY = 

