#include "board_widget.h"

// private ////////////////////////////////////
void BoardWidget::putTile(const int &x, const int &y)
{
    delete board[x][y];
    board[x][y] = new Tile(tileWidth, tileHeight, this);
    board[x][y]->setGeometry(x * tileWidth,
                             y * tileHeight,
                             tileWidth,
                             tileHeight);
}

void BoardWidget::initialiseBoard(int const & boardWidth, int const & boardHeight)
{
    board.initialize(boardWidth, boardHeight);
    for(int j = 0; j < board.getWidth(); j++)
        for(int k = 0; k < board.getHeight(); k++)
            putTile(j, k);
}

void BoardWidget::randomLayout()
{
    for(int j = 0; j < board.getWidth(); j++) {
        bool isEmpty = false;
        for(int k = board.getHeight() - 1; k >= 0 && !isEmpty; k--){
            isEmpty = std::rand() % (k + 2) == 0;
            if(isEmpty)
                board[j][k]->unsetColor();
            else
                board[j][k]->setColor();
        }
    }
    repaint();
}

void BoardWidget::newGameLayout()
{
    for(int j = 0; j < board.getWidth(); j++)
        for(int k = 0; k < board.getHeight(); k++)
            board[j][k]->setColor();
    repaint();
}

// protected ////////////////////////////////////
void BoardWidget::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        clickPoint = e->pos();
        emit mousePressed();
    }
}

// public ////////////////////////////////////
void BoardWidget::create(int const& width ,int const& height, int const& boardWidth ,int const& boardHeight)
{
    tileWidth = width / boardWidth;
    tileHeight = height / boardHeight;
    initialiseBoard(boardWidth, boardHeight);
    randomLayout();
}

// constructors ////////////////////////////////////
BoardWidget::BoardWidget(QWidget* parent)
    : QWidget(parent), board()
{}

// slots ////////////////////////////////////
void BoardWidget::stateChangedSlot(State const & state, int const & result, int const & moveCounter)
{
    switch(state){
        case IN_GAME:
            newGameLayout();
    }
}

void BoardWidget::countPointsSlot(int & result, int const & moveCounter)
{
    MoveColumnsAlgorithm alg;
    int emptyColumnsCount = alg.findEmptyColumnsLeft(board);
    emptyColumnsCount += alg.findEmptyColumnsRight(board);
    result += calculatePoints(emptyColumnsCount);
    if(moveCounter > 0)
        moveColumns(alg);
    repaint();
}

void BoardWidget::clearAreaSlot(int & moveCounter)
{
    if(removeArea()){
        moveCounter--;
        fallColumns();
        repaint();
    }
}

// private used in slots ///////////////////////////////
void BoardWidget::moveColumns(MoveColumnsAlgorithm & alg)
{
    alg.moveColumnsLeft(board);
    alg.moveColumnsRight(board);
}

bool BoardWidget::removeArea()
{
    clickPoint.rx() /= tileWidth;
    clickPoint.ry() /= tileHeight;
    if(clickPoint.ry() >= board.getHeight())
        clickPoint.ry()--;
    if(clickPoint.rx() >= board.getHeight())
        clickPoint.rx()--;
    QList<QPoint*> * area;
    FindAreaAlgorithm alg;
    area = alg.determinArea(board, clickPoint);
    if(area->size() == 0)
        return false;
    else
        for(int i = 0; i < area->size(); i++)
            board[area->at(i)->rx()][area->at(i)->ry()]->unsetColor();
    return true;
}

void BoardWidget::fallColumns()
{
    FallColumnsAlgorithm alg;
    alg.fallColumns(board);
}

int BoardWidget::calculatePoints(int const & x) const
{
    return (x + (x - 1) * 0.1 * x / 2) * 100;
}
