#-------------------------------------------------
#
# Project created by QtCreator 2015-02-20T19:23:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Relooker
target.path = /usr/bin
TEMPLATE = app

RC_ICONS = graph/RElooker.ico
ICON = graph/RElooker.icns


SOURCES += main.cpp\
        mainwindow.cpp \
    fichier.cpp \
    twodimension.cpp \
    visualizer.cpp \
    hexvisu.cpp \
    piechartwidget.cpp

HEADERS  += mainwindow.h \
    fichier.h \
    twodimension.h \
    visualizer.h \
    hexvisu.h \
    piechartwidget.h

FORMS    += mainwindow.ui

INSTALLS += target
