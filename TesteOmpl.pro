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
        mainwindow.cpp \
    qcustomplot.cpp \
    customdrawer.cpp \
    map2d.cpp \
    obstacle.cpp \
    mapstatevaliditychecker.cpp \
    plannercomparer.cpp \
    mainwindowviewmodel.cpp \
    customdrawer.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowviewmodel.cpp \
    map2d.cpp \
    mapstatevaliditychecker.cpp \
    obstacle.cpp \
    plannercomparer.cpp \
    qcustomplot.cpp \
    customdrawer.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindowviewmodel.cpp \
    map2d.cpp \
    mapstatevaliditychecker.cpp \
    obstacle.cpp \
    plannercomparer.cpp \
    qcustomplot.cpp

HEADERS += \
        mainwindow.h \
    qcustomplot.h \
    customdrawer.h \
    map2d.h \
    obstacle.h \
    point.h \
    mapstatevaliditychecker.h \
    plannercomparer.h \
    mainwindowviewmodel.h \
    plannerinterface.h \
    envinterface.h \
<<<<<<< HEAD
    utils.h
=======
    estreitoenv.h \
    rrtstarplanner.h \
    rrtconnectplanner.h \
    Planners/rrtplanner.h \
    customdrawer.h \
    envinterface.h \
    estreitoenv.h \
    mainwindow.h \
    mainwindowviewmodel.h \
    map2d.h \
    mapstatevaliditychecker.h \
    obstacle.h \
    plannercomparer.h \
    plannerinterface.h \
    point.h \
    qcustomplot.h \
    rrtconnectplanner.h \
    rrtstarplanner.h \
    Envs/estreitoenv.h \
    Planners/lazyrrtplanner.h \
    Planners/rrtconnectplanner.h \
    Planners/rrtplanner.h \
    Planners/rrtstarplanner.h \
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
    Planners/rrtsharpplanner.h \
    Planners/sstplanner.h \
    Planners/prmplanner.h \
    Planners/prmstarplanner.h \
    Planners/lazyprmplanner.h \
    Planners/lazyprmstarplanner.h \
    Planners/estplanner.h \
    Planners/sblplanner.h \
    Planners/kpiece1planner.h \
    Envs/cercadoenv.h \
    Envs/densoenv.h
>>>>>>> 11cfb3e912c64f7e3418fcc00b328fc66ffcf0b6

FORMS += \
        mainwindow.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += ompl
