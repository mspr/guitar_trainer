QMAKE_CXXFLAGS += -std=c++11

QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlhandler.h \
    fretboard/fretboardview.h \
    fretboard/fretboardnote.h \
    fretboard/fretboardaxis.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlhandler.cpp \
    fretboard/fretboardview.cpp \
    fretboard/fretboardnote.cpp \
    fretboard/fretboardaxis.cpp
