#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T12:34:17
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IMsoftware_server
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp

HEADERS  += widget.h \
    mythread.h \
    head.h

FORMS    += widget.ui

RESOURCES += \
    res.qrc
