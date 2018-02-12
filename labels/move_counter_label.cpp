#include "move_counter_label.h"

// slots ////////////////////////////////////
void MoveCounterLabel::stateChangedSlot(State const & state, int const & result, int const & moveCounter)
{
    switch(state){
        case IN_GAME:
            this->setText(QString::number(moveCounter));
            break;
        case OUT_OF_GAME:
            this->setText("");
            break;
    }
}

void MoveCounterLabel::moveCounterChangedSlot(int const & moveCounter)
{
    this->setText(QString::number(moveCounter));
}

// constructors ////////////////////////////////////
MoveCounterLabel::MoveCounterLabel(QWidget* parent)
    :ObsLabel(parent)
{}
