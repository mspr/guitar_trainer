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

QMAKE_CXXFLAGS += -std=c++11

QT += \
    widgets \

SOURCES += \
    mainwindow.cpp \
    outputwindow.cpp \
    messagehandler.cpp \
    outputscrollbar.cpp

HEADERS += \
    mainwindow.h \
    outputwindow.h \
    messagehandler.h \
    outputscrollbar.h

FORMS += \
    mainwindow.ui \
    outputwindow.ui

RESOURCES += \
    resources.qrc
