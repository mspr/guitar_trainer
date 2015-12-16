#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T21:32:11
#
#-------------------------------------------------

include(../defaults.pri)
include(music/music.pri)
include(fretboard/fretboard.pri)
include(output/output.pri)

TARGET = guitar_trainer
TEMPLATE = lib
DESTDIR = ./

QT += \
    widgets \

SOURCES += \
    mainwindow.cpp \
    messagehandler.cpp \
    application.cpp

HEADERS += \
    mainwindow.h \
    messagehandler.h \
    application.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
