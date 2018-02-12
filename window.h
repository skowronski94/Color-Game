#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QRect>
#include <QApplication>
#include <QDesktopWidget>
#include "board/board_widget.h"
#include "labels/obs_label.h"
#include "labels/move_counter_label.h"
#include "labels/result_label.h"
#include "buttons/actionbutton.h"
#include "game_controller.h"

class Window : public QMainWindow
{
    Q_OBJECT
private:
    GameController gameController;
    ResultLabel resultLabel;
    MoveCounterLabel moveCounterLabel;
    ActionButton actionButton;
    BoardWidget board;

    void makeMoveCounterLabel(ObsLabel*, QString const &, float const &, float const &, float const &, float const &);
    void makeResultLabel(ObsLabel*, QString const &, float const &, float const &, float const &, float const &);
    void makeActionButton(ActionButton*, QString const &, float const &, float const &, float const &, float const &);
    void makeBoard(BoardWidget* board, float const &pos_x_part, float const &pos_y_part, float const &width_part, float const &height_part);
public:
    explicit Window(QWidget *parent = nullptr);
};

#endif // WINDOW_H
