#include "actionbutton.h"

// constructors ////////////////////////////////////
ActionButton::ActionButton(QWidget* parent)
    :QPushButton(parent)
{}

// slots ////////////////////////////////////
void ActionButton::stateChangedSlot(State const & state, int const & result, int const & moveCounter)
{
    switch(state)
    {
        case IN_GAME:
            this->setText("COUNT");
            break;
        case OUT_OF_GAME:
            this->setText("START");
            break;
    }
}

