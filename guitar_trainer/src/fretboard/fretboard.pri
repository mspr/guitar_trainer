QT += \
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
    fretboard/play/fretboardplayscene.h \
    fretboard/edition/commandaddaxisfret.h \
    fretboard/edition/commandaddaxisstring.h \
    fretboard/edition/fretboardaxisfret.h \
    fretboard/edition/fretboardaxisstring.h \
    fretboard/edition/fretboardaxisbuilder.h \
    fretboard/fretboardscenebuilder.h \
    fretboard/play/fretboardplayscenebuilder.h \
    fretboard/edition/fretboardeditscenebuilder.h \
    fretboard/fretboardscenefilevalidator.h \
    fretboard/fretboardwindow.h \
    fretboard/play/fretboardplaywindow.h

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
    fretboard/play/fretboardplayscene.cpp \
    fretboard/edition/commandaddaxisfret.cpp \
    fretboard/edition/commandaddaxisstring.cpp \
    fretboard/edition/fretboardaxisfret.cpp \
    fretboard/edition/fretboardaxisstring.cpp \
    fretboard/edition/fretboardaxisbuilder.cpp \
    fretboard/fretboardscenebuilder.cpp \
    fretboard/play/fretboardplayscenebuilder.cpp \
    fretboard/edition/fretboardeditscenebuilder.cpp \
    fretboard/fretboardscenefilevalidator.cpp \
    fretboard/fretboardwindow.cpp \
    fretboard/play/fretboardplaywindow.cpp

FORMS += \
    fretboard/edition/fretboardeditwindow.ui \
    fretboard/play/fretboardplaywindow.ui
