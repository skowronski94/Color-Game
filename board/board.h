#ifndef BOARD_H
#define BOARD_H

#include "tile.h"

class Board
{
    int width;
    int height;
    Tile*** arr;

    void deleteArray();
public:
    int const & getWidth() const;
    int const & getHeight() const;
    Tile const * at(int const & j, int const & k) const;
    Tile ** operator[](int const & i) const;
    void initialize(int const & width, int const & height);

    Board();
    Board(int const & width, int const & height);
    ~Board();
};

#endif // BOARD_H

