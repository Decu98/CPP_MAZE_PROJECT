#include "maze.h"

using namespace std;


//Konstruktor
Maze::Maze(int x, int y, Maze *next, Maze *prev)
{
    x_ = x;
    y_ = y;
    next_ = next;
    prev_ = prev;
}

//Sprawdza czy ma wolne pola wokół
bool Maze::isEnd(int **pool,int w, int h){
    int x = this->getX(), y = this->getY(),
            E = 1, W = 1, S = 1, N = 1;
    if(x+1 < w){
        E = pool[2*(x+1)][2*y];
    }
    if(x-1 > 0){
        W = pool[2*(x-1)][2*y];
    }
    if(y+1 < h){
        S = pool[2*x][2*(y+1)];
    }
    if(y-1 > 0){
        N = pool[2*x][2*(y-1)];
    }
    return N != 0 && E != 0 && S != 0 && W != 0;
}

//Funkcje listy
void Maze::setPrev(Maze *prev){
    prev_ = prev;
}

void Maze::setNext(Maze *next){
    next_ = next;
}

//Zabudowanie labiryntu
void Maze::Buildings(int **&pool, int W, int H,int prct){
    if(prct != 0){
        int r_x, r_y;
        for(int i = 0 ; i < W*H*prct/100; i++){
            r_x = (rand()%(W-3))+2;
            r_y = (rand()%(H-3))+2;
            pool[2*r_x][2*r_y] = 2;
        }
    }
}

//Wejscie i wyjscie do labiryntu
void Maze::Opening(int **&pool, int W, int H, int in, int out){
    int i_x, o_x;
    for(int i = 0; i < in;i++){
        i_x = (rand()%(W-1))+1;
        pool[i_x*2][0] = 3;
        pool[i_x*2][1] = 3;
    }
    for(int i = 0; i < out;i++){
        o_x = (rand()%(W-1))+1;
        pool[o_x*2][H*2] = 4;
        pool[o_x*2][(H*2)-1] = 4;
    }

}

//Generowanie labiryntu z uzyciem listy
void Maze::Generate(Maze *&maze,int W, int H, int prct, int in, int out, int **&pool){
    int way = rand()%4;
    int i = 0,x = maze->getX(),y = maze->getY();
    maze->Buildings(pool,W,H,prct);
    do{
        while(maze->isEnd(pool,W,H)){
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
        else if(way == 2 && maze->getY()+1 < H){
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
    maze->Opening(pool,W,H,in,out);
    maze->Show(pool,W,H);
}

//Pokazanie labiryntu,wejsc, wyjsc i zabudowania w konsoli
void Maze::Show(int **pool,int W,int H){
    for(int i = 0 ; i < W*2+1; i++){
        for(int j = 0 ; j < H*2+1; j++){
            cout.width(2);
            if(pool[i][j] == 1){
                cout << ' ';
            }else if(pool[i][j] == 2){
                cout << '&';
            }else if(pool[i][j] == 3 || pool[i][j] == 4){
                cout << '>';
            }else{
                cout << '#';
            }
        }
        cout << endl;
    }
}




