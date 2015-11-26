QT += \
    widgets \
    xml \

HEADERS += \
    fretboard/fretboardscene.h \
    fretboard/fretboardxmlreader.h \
    fretboard/fretboardview.h \
    fretboard/fretboardnote.h \
    fretboard/edition/fretboardaxis.h \
    fretboard/edition/fretboardeditionwindow.h \
    fretboard/edition/fretboardeditionscene.h \
    fretboard/edition/fretboardeditionview.h \
    fretboard/fretboardxmlwriter.h \
    fretboard/edition/commandaddaxis.h \
    fretboard/edition/commandremoveaxis.h \
    fretboard/edition/commandmoveaxis.h \
    fretboard/edition/fretboardeditionsceneloader.h \
    fretboard/fretboardplayscene.h

SOURCES += \
    fretboard/fretboardscene.cpp \
    fretboard/fretboardxmlreader.cpp \
    fretboard/fretboardview.cpp \
    fretboard/fretboardnote.cpp \
    fretboard/edition/fretboardaxis.cpp \
    fretboard/edition/fretboardeditionwindow.cpp \
    fretboard/edition/fretboardeditionscene.cpp \
    fretboard/edition/fretboardeditionview.cpp \
    fretboard/fretboardxmlwriter.cpp \
    fretboard/edition/commandaddaxis.cpp \
    fretboard/edition/commandremoveaxis.cpp \
    fretboard/edition/commandmoveaxis.cpp \
    fretboard/edition/fretboardeditionsceneloader.cpp \
    fretboard/fretboardplayscene.cpp

FORMS += \
    fretboard/edition/fretboardeditionwindow.ui
