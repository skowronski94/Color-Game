#include "move_columns_algorithm.h"

// public ///////////////////////////////////////////
int MoveColumnsAlgorithm::findEmptyColumnsLeft(Board & board)
{
    emptyColumnLeftList.clear();
    filledColumnLeftList.clear();
    int emptyCounter = 0;
    for(int j = 0; j < board.getWidth() / 2; j++){
        bool isEmptyColumn = true;
        for(int k = 0; k < board.getHeight() && isEmptyColumn; k++)
            if(!board[j][k]->isEmpty())
                isEmptyColumn = false;
        if(isEmptyColumn){
            emptyCounter++;
            emptyColumnLeftList.append(j);
        }
        else
            filledColumnLeftList.append(j);
    }
    return emptyCounter;
}

void MoveColumnsAlgorithm::moveColumnsLeft(Board & board)
{
    toFillColumnList.clear();
    int emptyCount = emptyColumnLeftList.size();
    while(!emptyColumnLeftList.empty() && !filledColumnLeftList.empty()){
        int empty = emptyColumnLeftList.back();
        int filled = filledColumnLeftList.back();
        filledColumnLeftList.pop_back();
        if(filled < empty){
            emptyColumnLeftList.pop_back();
            toFillColumnList.append(filled);
            for(int i = 0; i < board.getHeight(); i++)
                board[empty][i]->setColor(board[filled][i]->getColor());
            if(!emptyColumnLeftList.empty()){
                if(emptyColumnLeftList.last() < filled)
                    emptyColumnLeftList.append(filled);
                else if(emptyColumnLeftList.first() > filled)
                    emptyColumnLeftList.insert(0, filled);
                for(int i = 0; i < emptyColumnLeftList.size() - 1; i++)
                    if(emptyColumnLeftList.at(i) < filled && emptyColumnLeftList.at(i + 1) > filled)
                        emptyColumnLeftList.insert(i, filled);
            }else
                emptyColumnLeftList.append(filled);
        }
    }
    for(int j = 0; j < emptyCount; j++)
        for(int  k = 0; k < board.getHeight(); k++)
            board[j][k]->setColor();
}

int MoveColumnsAlgorithm::findEmptyColumnsRight(Board & board)
{
    emptyColumnRightList.clear();
    filledColumnRightList.clear();
    int emptyCounter = 0;
    for(int j = board.getWidth() - 1; j >= board.getWidth() / 2; j--){
        bool isEmptyColumn = true;
        for(int k = 0; k < board.getHeight() && isEmptyColumn; k++)
            if(!board[j][k]->isEmpty())
                isEmptyColumn = false;
        if(isEmptyColumn){
            emptyCounter++;
            emptyColumnRightList.append(j);
        }
        else
            filledColumnRightList.append(j);
    }
    return emptyCounter;
}

void MoveColumnsAlgorithm::moveColumnsRight(Board & board)
{
    toFillColumnList.clear();
    int emptyCount = emptyColumnRightList.size();
    while(!emptyColumnRightList.empty() && !filledColumnRightList.empty()){
        int empty = emptyColumnRightList.back();
        int filled = filledColumnRightList.back();
        filledColumnRightList.pop_back();
        if(filled > empty){
            emptyColumnRightList.pop_back();
            toFillColumnList.append(filled);
            for(int i = 0; i < board.getHeight(); i++)
                board[empty][i]->setColor(board[filled][i]->getColor());
            if(!emptyColumnRightList.empty()){
                if(emptyColumnRightList.last() > filled)
                    emptyColumnRightList.append(filled);
                else if(emptyColumnRightList.first() < filled)
                    emptyColumnRightList.insert(0, filled);
                for(int i = 0; i < emptyColumnRightList.size() - 1; i++)
                    if(emptyColumnRightList.at(i) > filled && emptyColumnRightList.at(i + 1) < filled)
                        emptyColumnRightList.insert(i, filled);
            }else
                emptyColumnRightList += filled;
        }
    }
    for(int j = board.getWidth() - 1; j >= (board.getWidth() - emptyCount); j--)
        for(int  k = 0; k < board.getHeight(); k++)
            board[j][k]->setColor(); 
}

// constructors ////////////////////////////////////////////
MoveColumnsAlgorithm::MoveColumnsAlgorithm()
    : emptyColumnLeftList(), filledColumnLeftList(), toFillColumnList()
{}
