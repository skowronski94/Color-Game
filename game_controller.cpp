#include "game_controller.h"


// slots ////////////////////////////////////
void GameController::clickedSlot()
{
    switch(state){
        case IN_GAME:
            emit countPoints(result, moveCounter);
            emit resultChanged(result);
            break;
        case OUT_OF_GAME:
            state = IN_GAME;
            result = 0;
            moveCounter = 25;
            emit stateChanged(state, result, moveCounter);
            break;
    }
}

void GameController::mousePressedSlot()
{
    switch(state){
        case IN_GAME:
            emit clearArea(moveCounter);
            emit moveCounterChanged(moveCounter);
            if (moveCounter == 0) {
                emit countPoints(result, moveCounter);
                state = OUT_OF_GAME;
                emit stateChanged(state, result, moveCounter);
            }
    }
}

// constructors ////////////////////////////////////
GameController::GameController(QObject*  parent)
    : QObject(parent), result(0), moveCounter(0), state(OUT_OF_GAME)
{}
