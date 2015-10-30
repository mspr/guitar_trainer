QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlreader.h \
    fretboard/fretboardview.h \
    fretboard/fretboardnote.h \
    fretboard/fretboardaxis.h \
    fretboard/fretboardeditionwindow.h \
    fretboard/fretboardeditionscene.h \
    fretboard/fretboardeditionview.h \
    fretboard/fretboardxmlwriter.h \
    fretboard/commandaddaxis.h \
    fretboard/commandremoveaxis.h \
    fretboard/commandmoveaxis.h \
    fretboard/fretboardeditionsceneloader.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlreader.cpp \
    fretboard/fretboardview.cpp \
    fretboard/fretboardnote.cpp \
    fretboard/fretboardaxis.cpp \
    fretboard/fretboardeditionwindow.cpp \
    fretboard/fretboardeditionscene.cpp \
    fretboard/fretboardeditionview.cpp \
    fretboard/fretboardxmlwriter.cpp \
    fretboard/commandaddaxis.cpp \
    fretboard/commandremoveaxis.cpp \
    fretboard/commandmoveaxis.cpp \
    fretboard/fretboardeditionsceneloader.cpp

FORMS += \
    fretboard/fretboardeditionwindow.ui
