#ifndef MOVECOLUMNSALGORITHM_H
#define MOVECOLUMNSALGORITHM_H

#include <QDebug>
#include "tile.h"
#include "board.h"

class MoveColumnsAlgorithm
{
    QList<int> emptyColumnLeftList;
    QList<int> filledColumnLeftList;
    QList<int> emptyColumnRightList;
    QList<int> filledColumnRightList;
    QList<int> toFillColumnList;

public:
    int findEmptyColumnsLeft(Board & board);
    void moveColumnsLeft(Board & board);
    int findEmptyColumnsRight(Board & board);
    void moveColumnsRight(Board & board);

    MoveColumnsAlgorithm();
};

#endif // MOVECOLUMNSALGORITHM_H
