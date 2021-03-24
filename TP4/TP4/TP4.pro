TEMPLATE = app
TARGET = TP4
QT += core \
    gui
HEADERS += inscriptionelecteurinterface.h \
    inscriptioncandidatinterface.h \
    desinscrireinterface.h \
    tp4.h
SOURCES += inscriptionelecteurinterface.cpp \
    inscriptioncandidatinterface.cpp \
    desinscrireinterface.cpp \
    main.cpp \
    tp4.cpp
FORMS += inscriptionelecteurinterface.ui \
    inscriptioncandidatinterface.ui \
    desinscrireinterface.ui \
    tp4.ui
RESOURCES += 
LIBS += "../source/Debug/libsource.a"
INCLUDEPATH += "../source/."
