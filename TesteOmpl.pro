#-------------------------------------------------
#
# Project created by QtCreator 2018-06-19T18:09:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = TesteOmpl
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        customdrawer.cpp \
        mainwindow.cpp \
        mainwindowviewmodel.cpp \
        map2d.cpp \
        mapstatevaliditychecker.cpp \
        obstacle.cpp \
        plannercomparer.cpp \
        qcustomplot.cpp \
    plot.cpp \
    pointviewer.cpp \
    menuvariables.cpp \
    mapplannerconfiguration.cpp

HEADERS += \
        Envs/cercadoenv.h \
        Envs/densoenv.h \
        Envs/estreitoenv.h \
        Planners/estplanner.h \
        Planners/kpiece1planner.h \
        Planners/lazyprmplanner.h \
        Planners/lazyprmstarplanner.h \
        Planners/lazyrrtplanner.h \
        Planners/prmplanner.h \
        Planners/prmstarplanner.h \
        Planners/rrtconnectplanner.h \
        Planners/rrtplanner.h \
        Planners/rrtsharpplanner.h \
        Planners/rrtstarplanner.h \
        Planners/sblplanner.h \
        Planners/sstplanner.h \
        customdrawer.h \
        envinterface.h \
        mainwindow.h \
        mainwindowviewmodel.h \
        map2d.h \
        mapstatevaliditychecker.h \
        obstacle.h \
        plannercomparer.h \
        plannerinterface.h \
        point.h \
        qcustomplot.h \
        utils.h \
    Planners/planners.h \
    Envs/envs.h \
    plot.h \
    pointviewer.h \
    menuvariables.h \
    plannerconfigurationinterface.h \
    configurationinterface.h \
    mapplannerconfiguration.h \
    rangeconfiguration.h \
    goalbiasconfiguration.h

FORMS += \
        mainwindow.ui \
    plot.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += ompl
