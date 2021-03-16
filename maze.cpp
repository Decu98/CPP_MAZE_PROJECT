#include "maze.h"

Maze::Maze(int x, int y, Maze *next, Maze *prev)
{
    x_ = x;
    y_ = y;
    next_ = next;
    prev_ = prev;
}

bool Maze::isEnd(int **pool,int w){
    int x = this->getX(), y = this->getY(),
            E = 1, W = 1, S = 1, N = 1;
    if(x+2 < w){
        E = pool[x+2][y];
    }
    if(x-2 > -1){
        W = pool[x-2][y];
    }
    if(y+2 < w){
        S = pool[x][y+2];
    }
    if(y-2 > -1){
        N = pool[x][y-2];
    }
    if(N == 1 && E == 1 && S == 1 && W == 1){
        return true;
    }else{
        return false;
    }
}

void Maze::setPrev(Maze *prev){
    prev_ = prev;
}

void Maze::setNext(Maze *next){
    next_ = next;
}



