#-------------------------------------------------
#
# Project created by QtCreator 2019-09-03T21:12:00
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IMsoftware
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logwidget.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    logwidget.h \
    mythread.h

FORMS    += mainwindow.ui \
    logwidget.ui

RESOURCES += \
    res.qrc
