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

LIBS += -L../src -lguitar_trainer

SOURCES += \
    main.cpp \
    testnote.cpp \
    testinterval.cpp

HEADERS += \
    testnote.h \
    testinterval.h
