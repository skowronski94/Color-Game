TEMPLATE = app
TARGET = name_of_the_app

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    window.h \
    board/tile.h \
    game_controller/state.h \
    buttons/actionbutton.h \
    board/find_area_algorithm.h \
    board/move_columns_algorithm.h \
    board/board_widget.h \
    board/fall_columns_algorithm.h \
    game_controller.h \
    labels/move_counter_label.h \
    labels/result_label.h \
    labels/obs_label.h \
    board/board.h

SOURCES += \
    window.cpp \
    main.cpp \
    board/tile.cpp \
    buttons/actionbutton.cpp \
    board/find_area_algorithm.cpp \
    board/move_columns_algorithm.cpp \
    board/board_widget.cpp \
    board/fall_columns_algorithm.cpp \
    game_controller.cpp \
    labels/move_counter_label.cpp \
    labels/obs_label.cpp \
    labels/result_label.cpp \
    board/board.cpp
