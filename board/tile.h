#ifndef TILE_H
#define TILE_H

#include <QWidget>
#include <QPainter>
#include <QColor>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

class Tile : public QWidget
{
    Q_OBJECT
public:
    static std::map<int, QColor> const colorMap;
private:
    QColor const* color;
protected:
    int size_x;
    int size_y;
public:
    virtual QColor const* getColor() const;
    virtual void setColor();
    virtual void setColor(QColor const* c);
    virtual void unsetColor();
    virtual bool isEmpty() const;
// override
    virtual void paintEvent(QPaintEvent* e);

    explicit Tile(int const &x = 0, int const &y = 0, QWidget* parent = nullptr);
    explicit Tile(int const &x, int const &y, int const &color, QWidget* parent = nullptr);
};
#endif // TILE_H

