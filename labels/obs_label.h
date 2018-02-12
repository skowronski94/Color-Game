#ifndef OBSLABEL_H
#define OBSLABEL_H

#include <QDebug>
#include <QLabel>
#include "game_controller/State.h"

class ObsLabel : public QLabel
{
private slots:
    virtual void stateChangedSlot(State const & state, int const & result, int const & moveCounter) = 0;
    virtual void moveCounterChangedSlot(int const & moveCounter);
    virtual void resultChangedSlot(int const & result);
public:

    explicit ObsLabel(QWidget* parent = nullptr);
};

#endif // OBSLABEL_H
