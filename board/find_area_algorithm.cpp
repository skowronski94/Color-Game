#include "find_area_algorithm.h"

// private /////////////////////////////////////////////////
bool FindAreaAlgorithm::areaListContains(QPoint * p){
    for(int i = 0; i < areaList.size(); i++){
        QPoint* p_list = areaList.at(i);
        if(p_list->rx() == p->rx() && p_list->ry() == p->ry())
            return true;
    }
    return false;
}

void FindAreaAlgorithm::checkTile(Board & board, QPoint * p, QColor const * color){
    if(board[p->rx()][p->ry()]->getColor() == color && !areaListContains(p)){
        QPoint * point = new QPoint(p->rx(), p->ry());
        toCheckList.append(point);
        areaList.append(point);
    }
}

// public ///////////////////////////////////////////////////
QList<QPoint*> * FindAreaAlgorithm::determinArea(Board & board, QPoint & point){
    areaList.clear();
    if(board[point.rx()][point.ry()]->isEmpty())
        return &areaList;
    QColor const * color = board[point.rx()][point.ry()]->getColor();
    toCheckList.append(&point);
    areaList.append(&point);
    QPoint p;
    while(!toCheckList.isEmpty()){
        QPoint *p_center = toCheckList.back();
        toCheckList.pop_back();

        p.setX(p_center->rx() + 1);
        p.setY(p_center->ry());
        if(p.rx() < board.getWidth())
            checkTile(board, &p, color);

        p.setX(p_center->rx());
        p.setY(p_center->ry() + 1);
        if(p.ry() < board.getHeight())
            checkTile(board, &p, color);

        p.setX(p_center->rx() - 1);
        p.setY(p_center->ry());
        if(p.rx() >= 0)
            checkTile(board, &p, color);

        p.setX(p_center->rx());
        p.setY(p_center->ry() - 1);
        if(p.ry() >= 0)
            checkTile(board, &p, color);
    };
    return &areaList;
}

// constructors ///////////////////////////////////////////////////
FindAreaAlgorithm::FindAreaAlgorithm()
    : toCheckList(), areaList()
{}

FindAreaAlgorithm::~FindAreaAlgorithm()
{
    for(int i = 0; i < toCheckList.length(); i++)
        delete toCheckList[i];
    for(int i = 0; i < areaList.length(); i++)
        delete areaList[i];
}
