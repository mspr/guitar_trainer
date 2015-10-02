#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T21:32:11
#
#-------------------------------------------------

include(../defaults.pri)

TEMPLATE = app

CONFIG += console
CONFIG -= app_bundle

QT += widgets

SOURCES += main.cpp

LIBS += -L../src -lguitar_trainer
