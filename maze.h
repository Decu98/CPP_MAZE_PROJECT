#ifndef MAZE_H
#define MAZE_H

#include <ctime>
#include <iostream>

using namespace std;

class Maze
{
private:
    int x_, y_;
    Maze *next_,*prev_;

public:
    Maze(int,int,Maze*,Maze*);
    Maze *getPrev(){return prev_;}
    Maze *getNext(){return next_;}
    void setPrev(Maze *);
    void setNext(Maze *);
    bool isEnd(int **,int,int);
    int getX(){return x_;}
    int getY(){return y_;}
    void Generate(Maze *&,int,int,int,int,int,int **&);
    void Show(int **,int,int);
    void Buildings(int **&,int,int,int);
    void Opening(int **&,int,int,int,int);
    void moveTop(Maze *&,int**&);
    void moveBottom(Maze *&,int**&,int);
    void moveLeft(Maze *&,int**&);
    void moveRight(Maze *&,int**&,int);
    void nextStep(Maze *&,int,int);
};

#endif // MAZE_H
