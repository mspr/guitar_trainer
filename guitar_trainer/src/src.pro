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

QMAKE_CXXFLAGS += -std=c++11

QT += \
    widgets \

SOURCES += \
    mainwindow.cpp \
    messagehandler.cpp

HEADERS += \
    mainwindow.h \
    messagehandler.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc
