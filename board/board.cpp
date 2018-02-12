#include "board.h"

// private ///////////////////////////////////////
void Board::deleteArray()
{
    for(int j = 0; j < this->width; j++){
        arr[j] = new Tile*[this->height];
        for(int k = 0; k < this->height; k++)
            delete arr[j][k];
        delete[] arr[j];
    }
    delete[] arr;
}


// public ////////////////////////////////////////
int const & Board::getWidth() const
{
    return width;
}

int const & Board::getHeight() const
{
    return height;
}

Tile const * Board::at(int const & j, int const & k) const
{
    if(j < width && k < height)
        return arr[j][k];
    return nullptr;
}

Tile** Board::operator[](int const & i) const
{
    if(i < width)
        return arr[i];
    return nullptr;
}

void Board::initialize(int const & width, int const & height)
{
    deleteArray();
    this->width = width;
    this->height = height;
    arr = new Tile**[this->width];
    for(int j = 0; j < this->width; j++){
        arr[j] = new Tile*[this->height];
        for(int k = 0; k < this->height; k++)
            arr[j][k] = new Tile();
    }
}

// constructors ///////////////////////////////
Board::Board()
{
    this->width = 1;
    this->height = 1;
    arr = new Tile**[this->width];
    for(int j = 0; j < this->width; j++){
        arr[j] = new Tile*[this->height];
        for(int k = 0; k < this->height; k++)
            arr[j][k] = new Tile();
    }
}

Board::Board(int const & width, int const & height)
    :width(width), height(height)
{
    arr = new Tile**[this->width];
    for(int j = 0; j < this->width; j++)
        arr[j] = new Tile*[this->height];
}

Board::~Board()
{
    deleteArray();
}
