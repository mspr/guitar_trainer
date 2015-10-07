QMAKE_CXXFLAGS += -std=c++11

QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlhandler.h \
    fretboard/fretboardview.h \
    fretboard/freatboardnote.h \
    fretboard/fretboardaxis.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlhandler.cpp \
    fretboard/fretboardview.cpp \
    fretboard/freatboardnote.cpp \
    fretboard/fretboardaxis.cpp
