#ifndef MAZE_H
#define MAZE_H

#include <ctime>
#include <iostream>

using namespace std;

class Maze
{
private:
    int x_, y_, size_;
    Maze *prev_,*next_;

public:
    Maze(int);
    Maze();
    ~Maze();
    void clearMemory(Maze*);
    Maze *getPrev(){return prev_;}
    void setPrev(Maze *);
    void setWay(Maze*,Maze*,Maze*,Maze*);
    Maze *addNext(int,int);
    void setXY(int,int);
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
};

#endif // MAZE_H
