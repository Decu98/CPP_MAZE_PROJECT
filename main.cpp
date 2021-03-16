#include <iostream>
#include <time.h>
#include "maze.h"
#include "pool.h"

using namespace std;

void m_move(Maze *&maze, int **&pool,int W){
    int way = rand()%4;
    int i = 0;
    do{
        if(way == 0 && pool[maze->getX()][maze->getY()-2] == 0 && maze->getY()-2 > -1){
            cout << "N\n";
            i++;
        }
        if(way == 1 && pool[maze->getX()+2][maze->getY()] == 0 && maze->getX()+2 < W){
            cout << "E\n";
            i++;
        }
        if(way == 2 && pool[maze->getX()][maze->getY()+2] == 0 && maze->getY()+2 < W){
            cout << "S\n";
            i++;
        }
        if(way == 3 && pool[maze->getX()-2][maze->getY()] == 0 && maze->getX()-2 > -1){
            cout << "W\n";
            i++;
        }
        way = rand()%4;
    }while(i < 2);
}

int main()
{
    srand(time(nullptr));
    int W = 10, start_x = rand()%(W+1), start_y = rand()%(W+1);
    Maze first(start_x,start_y,nullptr,nullptr);
    Maze *start = &first;
    int **pool = pool_generate(W,start_x, start_y);
    m_move(start,pool,W);
}
