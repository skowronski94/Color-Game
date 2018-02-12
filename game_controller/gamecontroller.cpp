#include "gamecontroller.h"

// getters
/*
int const & GameController::getResult() const
{
    return result;
}

int const & GameController::getmoveCounter() const
{
    return moveCounter;
}

State const* const GameController::getState() const
{
    return &state;
}

// slots
void GameController::clickedSlot(bool checked)
{
    qInfo() << "clickedSlot()";
}*/

GameController::GameController(QObject*  parent)
    : QObject(parent), result(0), moveCounter(0)
{

}
