TEMPLATE = app
TARGET = name_of_the_app

QT = core gui
QT += widgets testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    ../../board/tile.h \
    ../../board/board.h \
    ../../board/move_columns_algorithm.h \


SOURCES += \
    test.cpp \
    ../../board/tile.cpp \
    ../../board/board.cpp \
    ../../board/move_columns_algorithm.cpp \

