#include <iostream>
#include <time.h>
#include "maze.h"
#include "pool.h"

using namespace std;

void m_move(Maze *&maze, int **&pool,int W){
    int way = rand()%4;;
    int i = 0,x = maze->getX(),y = maze->getY();
    do{
        while(maze->isEnd(pool,W)){
            if(maze->getPrev() != nullptr){
               maze = maze->getPrev();
            }else{
                i = 1;
                break;
            }
        }
        if(way == 0 && maze->getY()-2 > -1){
            if(pool[maze->getX()][maze->getY()-2] == 0){
                x = maze->getX();
                y = maze->getY()-2;
            }
        }
        else if(way == 1 && maze->getX()+2 < W){
            if(pool[maze->getX()+2][maze->getY()] == 0){
                x = maze->getX()+2;
                y = maze->getY();
            }
        }
        else if(way == 2 && maze->getY()+2 < W){
            if(pool[maze->getX()][maze->getY()+2] == 0){
                x = maze->getX();
                y = maze->getY()+2;
            }
        }
        else if(way == 3 && maze->getX()-2 > -1){
            if(pool[maze->getX()-2][maze->getY()] == 0){
                x = maze->getX()-2;
                y = maze->getY();
            }
        }
        if(pool[x][y] == 0){
            //cout << maze->getX() << " " << maze->getY() << endl;
            Maze *next = new Maze(x,y,nullptr,maze);
            maze->setNext(next);
            pool[x][y] = 1;
            pool[(maze->getX()+x)/2][(maze->getY()+y)/2] = 1;
            maze = maze->getNext();
        }
        way = rand()%4;
    }while(i  != 1);
    for(int i = 0 ; i < W; i++){
        for(int j = 0 ; j < W; j++){
            cout.width(2);
            cout << pool[i][j];
        }
        cout << endl;
    }
}

int main()
{
    srand(time(nullptr));
    int W = 10, start_x = rand()%(W+1), start_y = rand()%(W+1);
    Maze *start = new Maze(0,0,nullptr,nullptr);
    int **pool = pool_generate(W,0, 0);
    m_move(start,pool,W);
}
