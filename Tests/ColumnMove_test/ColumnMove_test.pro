TEMPLATE = app
TARGET = name_of_the_app

QT = core gui
QT += widgets testlib
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ../../board/tile.h

SOURCES += \
    test.cpp \
    ../../board/tile.cpp

