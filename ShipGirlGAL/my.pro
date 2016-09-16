#-------------------------------------------------
#
# Project created by QtCreator 2013-11-09T19:02:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my
TEMPLATE = app
INCLUDEPATH += /usr/include

SOURCES += main.cpp\
        widget.cpp \
    maincall.cpp \
    js.cpp \
    AES.cpp \
    EngineAPI.cpp \
    EngineBeh.cpp \
    InputEvent.cpp \
    gesture.cpp \
    animation.cpp \
    basics.cpp \
    reimplemen.cpp \
    sg_ui.cpp \
    sg_startgame.cpp

HEADERS  += widget.h \
    head.h \
    maincall.h \
    library.h \
    AES.h \
    js.h \
    macro.h \
    configure.h \
    gesture.h \
    basics.h \
    globalVar.h \
    reimplemen.h \
    animation.h \
    sg_ui.h \
    sg_startgame.h

FORMS    += widget.ui
QT += core gui

OTHER_FILES +=
QT += multimedia multimediawidgets
INSTALLS += target
QT += script
QMAKE_CXXFLAGS += -std=c++11

RESOURCES += \
    res.qrc

DISTFILES +=
