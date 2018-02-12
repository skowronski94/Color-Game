#ifndef RESULTLABEL_H
#define RESULTLABEL_H

#include "obs_label.h"

class ResultLabel : public ObsLabel
{
    Q_OBJECT
private slots:
    void stateChangedSlot(State const & state, int const & result, int const & moveCounter);
    void resultChangedSlot(int const & result);
public:

    explicit ResultLabel(QWidget* parent = nullptr);
};

#endif // RESULTLABEL_H
