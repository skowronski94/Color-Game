#ifndef FIND_AREA_ALGORITHM_H
#define FIND_AREA_ALGORITHM_H

#include <QDebug>
#include "tile.h"
#include "board.h"

class FindAreaAlgorithm
{
    QList<QPoint*> toCheckList;
    QList<QPoint*> areaList;

    bool areaListContains(QPoint * p);
    void checkTile(Board & board, QPoint * p, QColor const * color);
public:
    QList<QPoint*> * determinArea(Board & board, QPoint & point);

    FindAreaAlgorithm();
    ~FindAreaAlgorithm();
};

#endif // FIND_AREA_ALGORITHM_H
