#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <game_controller/state.h>

class ActionButton : public QPushButton
{
    Q_OBJECT
public:
    ActionButton(QWidget* parent = nullptr);
signals:
  // clicked();            // from QPushButton
public slots:
    void stateChangedSlot(State const & state, int const & result, int const & moveCounter);
};

#endif // ACTIONBUTTON_H
