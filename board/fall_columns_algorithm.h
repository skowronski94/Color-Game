#ifndef FALLCOLUMNSALGORITHM_H
#define FALLCOLUMNSALGORITHM_H

#include "tile.h"
#include "board.h"

class FallColumnsAlgorithm
{
    QList<int> emptyList;
    QList<int> filledList;

public:
    void fallColumns(Board & board);

    FallColumnsAlgorithm();
};

#endif // FALLCOLUMNSALGORITHM_H
