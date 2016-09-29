#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T12:25:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = taskmanager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newpostform.cpp \
    newpurposeform.cpp \
    settingsform.cpp \
    addnewtaskform.cpp \
    listalltasksform.cpp \
    taskmanagerform.cpp \
    createreportform.cpp

HEADERS  += mainwindow.h \
    newpostform.h \
    newpurposeform.h \
    settingsform.h \
    addnewtaskform.h \
    listalltasksform.h \
    taskmanagerform.h \
    createreportform.h

FORMS    += mainwindow.ui \
    newpostform.ui \
    newpurposeform.ui \
    settingsform.ui \
    addnewtaskform.ui \
    listalltasksform.ui \
    taskmanagerform.ui \
    createreportform.ui

RESOURCES += \
    res.qrc
