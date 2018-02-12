#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QDebug>
#include <QObject>
#include "game_controller/state.h"

class GameController: public QObject
{
    Q_OBJECT
private:
    int moveCounter;
    int result;
    State state;
signals:
    void stateChanged(State const & state, int const & result, int const & moveCounter);
    void moveCounterChanged(int const & moveCounter);
    void resultChanged(int const & result);
    void countPoints(int & result, int const & moveCounter);
    void clearArea(int & moveCounter);
private slots:
    void mousePressedSlot();
    void clickedSlot();
public:

    GameController(QObject*  parent = nullptr);
};

#endif // GAMECONTROLLER_H
