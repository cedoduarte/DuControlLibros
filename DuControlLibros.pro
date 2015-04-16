#-------------------------------------------------
#
# Project created by QtCreator 2014-04-26T13:56:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DuControlLibros
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    agregadialog.cpp \
    buscadialog.cpp \
    eliminadialog.cpp \
    editadialog.cpp \
    basedatos.cpp

HEADERS  += mainwindow.h \
    agregadialog.h \
    entidadlibro.h \
    buscadialog.h \
    eliminadialog.h \
    editadialog.h \
    basedatos.h

FORMS    += mainwindow.ui \
    agregadialog.ui \
    buscadialog.ui \
    eliminadialog.ui \
    editadialog.ui

RESOURCES += \
    icons.qrc
