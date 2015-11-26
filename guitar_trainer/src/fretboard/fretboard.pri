QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlreader.h \
    fretboard/fretboardview.h \
    fretboard/fretboardnote.h \
    fretboard/edition/fretboardaxis.h \
    fretboard/edition/fretboardeditwindow.h \
    fretboard/edition/fretboardeditscene.h \
    fretboard/edition/fretboardeditview.h \
    fretboard/fretboardxmlwriter.h \
    fretboard/edition/commandaddaxis.h \
    fretboard/edition/commandremoveaxis.h \
    fretboard/edition/commandmoveaxis.h \
    fretboard/edition/fretboardeditsceneloader.h \
    fretboard/fretboardplayscene.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlreader.cpp \
    fretboard/fretboardview.cpp \
    fretboard/fretboardnote.cpp \
    fretboard/edition/fretboardaxis.cpp \
    fretboard/edition/fretboardeditwindow.cpp \
    fretboard/edition/fretboardeditscene.cpp \
    fretboard/edition/fretboardeditview.cpp \
    fretboard/fretboardxmlwriter.cpp \
    fretboard/edition/commandaddaxis.cpp \
    fretboard/edition/commandremoveaxis.cpp \
    fretboard/edition/commandmoveaxis.cpp \
    fretboard/edition/fretboardeditsceneloader.cpp \
    fretboard/fretboardplayscene.cpp

FORMS += \
    fretboard/edition/fretboardeditwindow.ui
