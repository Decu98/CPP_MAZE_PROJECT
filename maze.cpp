#include "maze.h"

Maze::Maze(int x, int y, Maze *next, Maze *prev)
{
    x_ = x;
    y_ = y;
    next_ = next;
    prev_ = prev;
}


void Maze::setPrev(Maze *prev){
    prev_ = prev;
}


