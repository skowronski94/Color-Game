#include "obs_label.h"

// private slots ///////////////////////////////////////////////////
void ObsLabel::moveCounterChangedSlot(int const & moveCounter)
{}

void ObsLabel::resultChangedSlot(int const & result)
{}

// constructors ///////////////////////////////////////////////
ObsLabel::ObsLabel(QWidget* parent)
    :QLabel(parent)
{}
