#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <ctime>
#include "pool.h"

class Maze
{
private:
    int x_, y_;
    Maze *next_,*prev_;

public:
    Maze(int,int,Maze*,Maze*);
    Maze *getPrev(){return prev_;}
    Maze *getNext(){return next_;}
    Maze &getThis(){return *this;}
    void setPrev(Maze *);
    void setNext(Maze *);
    bool isEnd(int **,int);
    int getX(){return x_;}
    int getY(){return y_;}
    void Generate(Maze *&,int);
    void Show(int **,int);
};

#endif // MAZE_H
