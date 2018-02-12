#include "result_label.h"

// slots ////////////////////////////////////
void ResultLabel::stateChangedSlot(State const & state, int const & result, int const & moveCounter)
{
    this->setText(QString::number(result));
}

void ResultLabel::resultChangedSlot(int const & result)
{
    this->setText(QString::number(result));
}

// constructors ////////////////////////////////////
ResultLabel::ResultLabel(QWidget* parent)
    :ObsLabel(parent)
{}
