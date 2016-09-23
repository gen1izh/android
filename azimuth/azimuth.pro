#-------------------------------------------------
#
# Project created by QtCreator 2016-09-23T10:44:03
#
#-------------------------------------------------

QT       += core gui positioning sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = azimuth
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    orm/models/pointsmodel.cpp \
    orm/models/pointsqdjangomodel.cpp \
    orm/db/QDjango.cpp \
    orm/db/QDjangoMetaModel.cpp \
    orm/db/QDjangoModel.cpp \
    orm/db/QDjangoQuerySet.cpp \
    orm/db/QDjangoWhere.cpp

HEADERS  += mainwindow.h \
    orm/models/pointsmodel.h \
    orm/models/pointsqdjangomodel.h \
    orm/db/QDjango.h \
    orm/db/QDjango_p.h \
    orm/db/QDjangoMetaModel.h \
    orm/db/QDjangoModel.h \
    orm/db/QDjangoQuerySet.h \
    orm/db/QDjangoQuerySet_p.h \
    orm/db/QDjangoWhere.h \
    orm/db/QDjangoWhere_p.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
