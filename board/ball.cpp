#include "ball.h"
#include <QDebug>

std::map<int, QColor> const Ball::colorMap = {{0, Qt::green},
                                                  {1, Qt::yellow},
                                                  {2, Qt::cyan},
                                                  {3, Qt::blue}};
// Public methods
QColor const* Ball::getColor() const {
    return color;
}

void Ball::setColor(){
    color = &colorMap.at(std::rand() % colorMap.size());
    qInfo() << "\n Ball::setColor()" << color;
    repaint();
}


bool Ball::isEmpty() const {
    return false;
}

// Public override methods
void Ball::paintEvent(QPaintEvent* e) {
    Tile::paintEvent(e);
    QPainter painter(this);
    //painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);
    painter.setBrush(QBrush(*color));
    painter.drawEllipse(0, 0, size_x, size_y);
    //painter.end();
}

// Constructors
Ball::Ball(/*int const &x, int const &y,*/ int const &size_x, int const &size_y, QWidget *parent)
    : Tile(/*x, y, */size_x, size_y, parent)
{
    color = &colorMap.at(std::rand() % colorMap.size());
}
