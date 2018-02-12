#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QDebug>
#include <QObject>
#include "../buttons/actionbutton.h"
#include "state.h"

class GameController: public QObject
{
    Q_OBJECT
private:
    int moveCounter;
    int result;
    State state;

    //inline int const & getResult() const;
    //inline int const & getmoveCounter() const;
   // inline State const* const getState() const;

signals:
    void stateChanged(State const & state);
    void moveCounterChanged(int const & moveCounter);
    void resultChanged(int const & result);
    void countPoints(int & result);
    void clearArea(int & moveCounter);

private slots:
   // void mousePressedSlot();
    //void clickedSlot(bool checked);

public:
    GameController(QObject*  parent = nullptr);
};

#endif // GAMECONTROLLER_H
