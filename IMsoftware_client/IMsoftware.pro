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
    mythread.cpp \
    widget/logwidget.cpp \
    widget/mainform.cpp \
    widget/regwidget.cpp \
    ui/collapseviewitem.cpp \
    ui/litteriem.cpp \
    ui/colorpickform.cpp \
    ui/moveableframelesswindow.cpp \
    ui/collapseview.cpp \
    src/config.cpp

HEADERS  += \
    mythread.h \
    widget/logwidget.h \
    widget/mainform.h \
    widget/regwidget.h \
    head.h \
    ui/collapseviewitem.h \
    ui/litteriem.h \
    ui/colorpickform.h \
    ui/moveableframelesswindow.h \
    ui/collapseview.h \
    src/singleton.h \
    src/config.h

FORMS    += \
    widget/logwidget.ui \
    widget/mainform.ui \
    widget/regwidget.ui \
    ui/collapseviewitem.ui \
    ui/litteriem.ui \
    ui/colorpickform.ui \
    ui/collapseview.ui

RESOURCES += \
    res.qrc
