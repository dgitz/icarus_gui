#-------------------------------------------------
#
# Project created by QtCreator 2016-07-24T08:40:11
#
#-------------------------------------------------

QT       += core gui
QT += gui
QT += network widgets
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Diagnostics_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    receiver.cpp \
    transmitter.cpp \
    udpmessage.cpp

HEADERS  += mainwindow.h \
    helper.h \
    receiver.h \
    transmitter.h \
    udpmessage.h

FORMS    += mainwindow.ui


CONFIG += mobility
MOBILITY = 
