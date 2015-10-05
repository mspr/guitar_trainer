#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T21:32:11
#
#-------------------------------------------------

include(../defaults.pri)

TEMPLATE = app

QT += testlib

CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    testnote.cpp \
    testinterval.cpp

LIBS += -L../src -lguitar_trainer

HEADERS += \
    testnote.h \
    testinterval.h
