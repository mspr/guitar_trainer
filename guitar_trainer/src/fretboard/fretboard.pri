QMAKE_CXXFLAGS += -std=c++11

QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlparser.h \
    fretboard/fretboardview.h \
    fretboard/fretboardnote.h \
    fretboard/fretboardaxis.h \
    fretboard/fretboardeditionwindow.h \
    fretboard/fretboardeditionscene.h \
    fretboard/fretboardeditionview.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlparser.cpp \
    fretboard/fretboardview.cpp \
    fretboard/fretboardnote.cpp \
    fretboard/fretboardaxis.cpp \
    fretboard/fretboardeditionwindow.cpp \
    fretboard/fretboardeditionscene.cpp \
    fretboard/fretboardeditionview.cpp

FORMS += \
    fretboard/fretboardeditionwindow.ui
