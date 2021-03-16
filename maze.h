#ifndef MAZE_H
#define MAZE_H


class Maze
{
private:
    int x_, y_;
    Maze *next_,*prev_;

public:
    Maze(int,int,Maze*,Maze*);
    ~Maze();
    Maze *getPrev(){return prev_;}
    Maze *getNext(){return next_;}
    void setPrev(Maze *);
    int getX(){return x_;}
    int getY(){return y_;}

};

#endif // MAZE_H
