#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T21:32:11
#
#-------------------------------------------------

TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = \
	src \
	app \
	tests

app.depends = src
tests.depends = src
	