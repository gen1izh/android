#-------------------------------------------------
#
# Project created by QtCreator 2016-08-27T11:21:18
#
#-------------------------------------------------

QT       += core gui positioning sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Dinner_planner
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    orm/db/QDjango.cpp \
    orm/db/QDjangoMetaModel.cpp \
    orm/db/QDjangoModel.cpp \
    orm/db/QDjangoQuerySet.cpp \
    orm/db/QDjangoWhere.cpp \
    orm/models/dishlistqdjangomodel.cpp \
    orm/models/dishmenubydayqdjangomodel.cpp \
    orm/models/dishsbydaymodel.cpp \
    orm/models/dishslistmodel.cpp \
    dishslistform.cpp \
    lunchtimeslist.cpp \
    newdishform.cpp \
    models.cpp \
    dishsbytimeform.cpp \
    farplannerform.cpp \
    basketform.cpp \
    versioninfoform.cpp

HEADERS  += mainwindow.h \
    orm/db/QDjango.h \
    orm/db/QDjango_p.h \
    orm/db/QDjangoMetaModel.h \
    orm/db/QDjangoModel.h \
    orm/db/QDjangoQuerySet.h \
    orm/db/QDjangoQuerySet_p.h \
    orm/db/QDjangoWhere.h \
    orm/db/QDjangoWhere_p.h \
    orm/models/dishlistqdjangomodel.h \
    orm/models/dishmenubydayqdjangomodel.h \
    orm/models/dishsbydaymodel.h \
    orm/models/dishslistmodel.h \
    dishslistform.h \
    lunchtimeslist.h \
    newdishform.h \
    models.h \
    dishsbytimeform.h \
    farplannerform.h \
    basketform.h \
    versioninfoform.h

FORMS    += mainwindow.ui \
    dishslistform.ui \
    lunchtimeslist.ui \
    newdishform.ui \
    dishsbytimeform.ui \
    farplannerform.ui \
    basketform.ui \
    versioninfoform.ui

CONFIG += mobility

CONFIG += c++11
MOBILITY = 

RESOURCES += \
    images_resources.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

