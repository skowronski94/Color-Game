#include "fall_columns_algorithm.h"

// public //////////////////////////////////////
void FallColumnsAlgorithm::fallColumns(Board & board)
{
    for(int j = 0; j < board.getWidth(); j++){
        emptyList.clear();
        filledList.clear();
        for(int k = 0; k < board.getHeight(); k++){
            if(board[j][k]->isEmpty())
                emptyList.append(k);
            else
                filledList.append(k);
        }
        if(!emptyList.empty())
            while(!filledList.empty()){
                int e = emptyList.back();
                int f = filledList.back();
                if(e < f)
                    filledList.pop_back();
                else{
                    board[j][e]->setColor(board[j][f]->getColor());
                    board[j][f]->unsetColor();
                    emptyList.pop_back();
                    if(emptyList.empty())
                        emptyList.append(f);
                    else if(f > emptyList.back())
                        emptyList.append(f);
                    else if(f < emptyList.first())
                        emptyList.insert(0, f);
                    else
                        for(int i = 1; i < emptyList.length(); i++){
                            if(f > emptyList.at(i - 1) && f < emptyList.at(i))
                                emptyList.insert(i, f);
                        }
                    filledList.pop_back();
                }
        }
    }
}

// constructors ///////////////////////////////////
FallColumnsAlgorithm::FallColumnsAlgorithm()
    :emptyList(), filledList()
{}
