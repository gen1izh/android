#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T12:25:59
#
#-------------------------------------------------

QT       += core gui sql

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
    createreportform.cpp \
    commonsharedsingleton.cpp \
    orm/db/QDjango.cpp \
    orm/db/QDjangoMetaModel.cpp \
    orm/db/QDjangoModel.cpp \
    orm/db/QDjangoQuerySet.cpp \
    orm/db/QDjangoWhere.cpp \
    orm/models/taskmodel.cpp \
    orm/models/taskqdjangomodel.cpp \
    orm/models/postmodel.cpp \
    orm/models/postqdjangomodel.cpp \
    orm/models/purposemodel.cpp \
    orm/models/purposeqdjangomodel.cpp

HEADERS  += mainwindow.h \
    newpostform.h \
    newpurposeform.h \
    settingsform.h \
    addnewtaskform.h \
    listalltasksform.h \
    taskmanagerform.h \
    createreportform.h \
    commonsharedsingleton.h \
    orm/db/QDjango.h \
    orm/db/QDjango_p.h \
    orm/db/QDjangoMetaModel.h \
    orm/db/QDjangoModel.h \
    orm/db/QDjangoQuerySet.h \
    orm/db/QDjangoQuerySet_p.h \
    orm/db/QDjangoWhere.h \
    orm/db/QDjangoWhere_p.h \
    orm/models/taskmodel.h \
    orm/models/taskqdjangomodel.h \
    orm/models/postmodel.h \
    orm/models/postqdjangomodel.h \
    orm/models/purposemodel.h \
    orm/models/purposeqdjangomodel.h

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
