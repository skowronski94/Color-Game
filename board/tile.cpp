#include "tile.h"

std::map<int, QColor> const Tile::colorMap = {{0, Qt::white},
                                              {1, Qt::green},
                                              {2, Qt::yellow},
                                              {3, Qt::cyan},
                                              {4, Qt::blue}};

// public ////////////////////////////////////////////////////////
QColor const* Tile::getColor() const
{
    return color;
}

void Tile::setColor()
{
    color = &colorMap.at(1 + std::rand() % (colorMap.size() - 1));
}

void Tile::setColor(QColor const* c)
{
    color = c;
}

void Tile::unsetColor()
{
    color = &colorMap.at(0);
}

bool Tile::isEmpty() const
{
    return color == &colorMap.at(0);
}

// public override ///////////////////////////////////////////////
void Tile::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setBrush(QBrush(Qt::white));
    painter.drawRect(0, 0, size_x, size_y);
    if(!isEmpty()){
        painter.setBrush(QBrush(*color));
        painter.drawEllipse(0, 0, size_x, size_y);
    }
}

// constructors ////////////////////////////////////////////////
Tile::Tile(int const &size_x, int const &size_y, QWidget* parent)
    : QWidget(parent), size_x(size_x), size_y(size_y)
{
    color = &colorMap.at(0);
}

Tile::Tile(int const &x, int const &y, int const &color, QWidget* parent)
    : Tile(x, y, parent)
{
    this->color = &colorMap.at(color);
}



