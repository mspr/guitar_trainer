QMAKE_CXXFLAGS += -std=c++11

QT += \
    xml \

HEADERS += \
    model/note.h \
    model/interval.h \
    model/fretboardscene.h \
    model/fretboardxmlhandler.h

SOURCES += \
    model/note.cpp \
    model/interval.cpp \
    model/fretboardscene.cpp \
    model/fretboardxmlhandler.cpp
