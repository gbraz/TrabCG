#-------------------------------------------------
#
# Project created by QtCreator 2015-11-04T15:02:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrabCG
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    face.cpp \
    vertice.cpp \
    objeto.cpp \
    camera.cpp \
    calc.cpp \
    pixel.cpp

HEADERS  += mainwindow.h \
    face.h \
    vertice.h \
    objeto.h \
    camera.h \
    calc.h \
    pixel.h

FORMS    += mainwindow.ui