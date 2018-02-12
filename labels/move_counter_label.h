#ifndef MOVECOUNTERLABEL_H
#define MOVECOUNTERLABEL_H

#include "obs_label.h"

class MoveCounterLabel : public ObsLabel
{
    Q_OBJECT
private slots:
    void stateChangedSlot(State const & state, int const & result, int const & moveCounter);
    void moveCounterChangedSlot(int const & moveCounter);
public:

    explicit MoveCounterLabel(QWidget* parent = nullptr);
};

#endif // MOVECOUNTERLABEL_H
