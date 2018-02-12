#ifndef BOARD_WIDGET_H
#define BOARD_WIDGET_H

#include <QWidget>
#include <QMouseEvent>
#include <vector>
//#include "tile.h"
#include "board.h"
#include "game_controller/state.h"
#include "find_area_algorithm.h"
#include "move_columns_algorithm.h"
#include "fall_columns_algorithm.h"

class BoardWidget : public QWidget
{
    Q_OBJECT
private:
    int tileWidth;
    int tileHeight;
    QPoint clickPoint;
    Board board;

private:
    void putTile(const int &x, const int &y);
    void initialiseBoard(int const & width, int const & height);
    void randomLayout();
    void newGameLayout();
protected:
    void mousePressEvent(QMouseEvent * e);
public:
    void create(int const& width ,int const& height, int const& boardWidth ,int const& boardHeight);

    BoardWidget(QWidget* parent = nullptr);
signals:
    void mousePressed();
public slots:
    void stateChangedSlot(State const & state, int const & result, int const & moveCounter);
    void countPointsSlot(int & result, int const & moveCounter);
    void clearAreaSlot(int & moveCounter);
private: // used in slots
    void moveColumns(MoveColumnsAlgorithm & alg);
    bool removeArea();
    void fallColumns();
    int calculatePoints(int const & x) const;
};

#endif // BOARD_WIDGET_H
