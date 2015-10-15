#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T21:32:11
#
#-------------------------------------------------

include(../defaults.pri)
include(music/music.pri)
include(fretboard/fretboard.pri)

TARGET = guitar_trainer
TEMPLATE = lib
DESTDIR = ./

QT += \
    widgets \

SOURCES += \
    mainwindow.cpp \
    outputwindow.cpp \
    messagehandler.cpp

HEADERS += \
    mainwindow.h \
    outputwindow.h \
    messagehandler.h

FORMS += \
    mainwindow.ui \
    outputwindow.ui

RESOURCES += \
    resources.qrc
