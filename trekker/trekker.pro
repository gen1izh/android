#-------------------------------------------------
#
# Project created by QtCreator 2016-09-22T12:19:51
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets positioning

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trekker
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    orm/db/QDjango.cpp \
    orm/db/QDjangoMetaModel.cpp \
    orm/db/QDjangoModel.cpp \
    orm/db/QDjangoQuerySet.cpp \
    orm/db/QDjangoWhere.cpp \
    orm/models/treksqdjangomodel.cpp \
    orm/models/pointsqdjangomodel.cpp \
    orm/models/treksmodel.cpp \
    orm/models/pointsmodel.cpp

HEADERS  += mainwindow.h \
    orm/db/QDjango.h \
    orm/db/QDjango_p.h \
    orm/db/QDjangoMetaModel.h \
    orm/db/QDjangoModel.h \
    orm/db/QDjangoQuerySet.h \
    orm/db/QDjangoQuerySet_p.h \
    orm/db/QDjangoWhere.h \
    orm/db/QDjangoWhere_p.h \
    orm/models/treksqdjangomodel.h \
    orm/models/pointsqdjangomodel.h \
    orm/models/treksmodel.h \
    orm/models/pointsmodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc
