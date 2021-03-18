#include "maze.h"

using namespace std;

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
    if(x+1 < w){
        E = pool[2*(x+1)][2*y];
    }
    if(x-1 > 0){
        W = pool[2*(x-1)][2*y];
    }
    if(y+1 < w){
        S = pool[2*x][2*(y+1)];
    }
    if(y-1 > 0){
        N = pool[2*x][2*(y-1)];
    }
    return N == 1 && E == 1 && S == 1 && W == 1;
}

void Maze::setPrev(Maze *prev){
    prev_ = prev;
}

void Maze::setNext(Maze *next){
    next_ = next;
}

void Maze::Generate(Maze *&maze,int W){
    int way = rand()%4;
    int **pool = pool_generate(W+1,maze->getX(),maze->getY());
    int i = 0,x = maze->getX(),y = maze->getY();
    do{
        while(maze->isEnd(pool,W)){
            if(maze->getPrev() != nullptr){
                maze = maze->getPrev();
                delete maze->getNext();
            }else{
                i = 1;
                way = 4;
                delete maze;
                break;
            }
        }
        if(way == 0 && maze->getY()-1 > 0){
            if(pool[2*maze->getX()][2*(maze->getY()-1)] == 0){
                x = maze->getX();
                y = maze->getY()-1;
            }
        }
        else if(way == 1 && maze->getX()+1 < W){
            if(pool[2*(maze->getX()+1)][2*maze->getY()] == 0){
                x = maze->getX()+1;
                y = maze->getY();
            }
        }
        else if(way == 2 && maze->getY()+1 < W){
            if(pool[2*maze->getX()][2*(maze->getY()+1)] == 0){
                x = maze->getX();
                y = maze->getY()+1;
            }
        }
        else if(way == 3 && maze->getX()-1 > 0){
            if(pool[2*(maze->getX()-1)][2*maze->getY()] == 0){
                x = maze->getX()-1;
                y = maze->getY();
            }
        }
        if(pool[2*x][2*y] == 0){
            Maze *next = new Maze(x,y,nullptr,maze);
            maze->setNext(next);
            pool[2*x][2*y] = 1;
            pool[(maze->getX()+x)][(maze->getY()+y)] = 1;
            maze = maze->getNext();
        }
        way = rand()%4;
    }while(i  != 1);
    maze->Show(pool,W);
}

void Maze::Show(int **pool,int W){
    for(int i = 0 ; i < W*2+1; i++){
        for(int j = 0 ; j < W*2+1; j++){
            cout.width(2);
            if(pool[i][j] == 1){
                cout << ' ';
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }
    for(int i = 0; i < 2*W; i++){
        delete [] pool[i];
    }
    delete [] pool;
}



