#-------------------------------------------------
#
# Project created by QtCreator 2014-04-27T13:58:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = components_src
TEMPLATE = app


SOURCES += main.cpp\
    container/Cpu.cpp \
    container/MotherBoard.cpp \
    container/Ram.cpp \
    container/Reader.cpp \
    container/VideoCard.cpp \
    container/Writer.cpp \
    mainwindow.cpp \
    adddialog.cpp


HEADERS  += mainwindow.h \
    container/ComponentOutIn.h \
    container/Cpu.h \
    container/Elem.h \
    container/List.h \
    container/MotherBoard.h \
    container/Ram.h \
    container/Reader.h \
    container/TreeIterator.h \
    container/TreePreorderIterator.h \
    container/VideoCard.h \
    container/Writer.h \
    mainwindow.h \
    container/OATree.h \
    adddialog.h


FORMS    += mainwindow.ui \
    adddialog.ui
