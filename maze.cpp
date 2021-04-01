#include "maze.h"

using namespace std;


//Konstruktor
Maze::Maze(){
    x_ = 1;
    y_ = 1;
    size_ = 0;
    prev_ = nullptr;
    next_ = nullptr;
}

Maze::~Maze(){
    for(int i = 0 ; i < size_; i++){
        this->clearMemory(this->next_+i);
    }
    delete this;
}

void Maze::clearMemory(Maze *current){
    for(int i = 0; i < size_; i++){
        current->clearMemory(current->next_+1);
    }
    delete current;
}

Maze *Maze::addNext(int x,int y){
    if(next_){
       Maze *next = next_+1;
       next->setXY(x,y);
       next->setPrev(this);
       this->size_++;
       return next;
    }else{
       this->next_ = new Maze();
       this->next_->setXY(x,y);
       this->next_->setPrev(this);
       this->size_++;
       return next_;
    }
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

void Maze::setXY(int x, int y){
    x_ = x;
    y_ = y;
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
    int i = 0;
    maze->Buildings(pool,W,H,prct);
    do{
        while(maze->isEnd(pool,W,H)){
            if(maze->getPrev() != nullptr){
                maze = maze->getPrev();
            }else{
                i = 1;
                way = 4;
                break;
            }
        }
        switch(way){
        case 0 :
            maze->moveTop(maze,pool);
            break;
        case 1 :
            maze->moveRight(maze,pool,W);
            break;
        case 2 :
            maze->moveBottom(maze,pool,H);
            break;
        case 3 :
            maze->moveLeft(maze,pool);
            break;
        }
        way = rand()%4;
    }while(i != 1);
    maze->Opening(pool,W,H,in,out);
    maze->Show(pool,W,H);
}

//Pokazanie labiryntu,wejsc, wyjsc i zabudowania w konsoli
void Maze::Show(int **pool,int W,int H){
    for(int i = 0 ; i < W*2+1; i++){
        for(int j = 0 ; j < H*2+1; j++){
            cout.width(2);
            if(pool[i][j] == 1){
                //Scierzka labiryntu
                cout << ' ';
            }else if(pool[i][j] == 2){
                //Zabudowanie, niedostepne pole
                cout << '&';
            }else if(pool[i][j] == 3 || pool[i][j] == 4){
                //Wejscie i wyjscie
                cout << '>';
            }else{
                //Sciany labiryntu
                cout << '#';
            }
        }
        cout << endl;
    }
}

void Maze::moveBottom(Maze *&maze, int **&pool, int Height){
    if(maze->getY()+1 < Height){
        if(pool[2*maze->getX()][2*(maze->getY()+1)] == 0){
            int x = maze->getX();
            int y = maze->getY()+1;
            if(pool[2*x][2*y] == 0){
                pool[2*x][2*y] = 1;
                pool[(maze->getX()+x)][(maze->getY()+y)] = 1;
                Maze *next = maze->addNext(x,y);
                maze = next;
            }
        }
    }
}

void Maze::moveTop(Maze *&maze, int **&pool){
    if(maze->getY()-1 > 0){
        if(pool[2*maze->getX()][2*(maze->getY()-1)] == 0){
            int x = maze->getX();
            int y = maze->getY()-1;
            if(pool[2*x][2*y] == 0){
                pool[2*x][2*y] = 1;
                pool[(maze->getX()+x)][(maze->getY()+y)] = 1;
                Maze *next = maze->addNext(x,y);
                maze = next;
            }
        }
    }
}

void Maze::moveLeft(Maze *&maze, int **&pool){
    if(maze->getX()-1 > 0){
        if(pool[2*(maze->getX()-1)][2*maze->getY()] == 0){
            int x = maze->getX()-1;
            int y = maze->getY();
            if(pool[2*x][2*y] == 0){
                pool[2*x][2*y] = 1;
                pool[(maze->getX()+x)][(maze->getY()+y)] = 1;
                Maze *next = maze->addNext(x,y);
                maze = next;
            }
        }
    }
}

void Maze::moveRight(Maze *&maze, int **&pool, int Width){
    if(maze->getX()+1 < Width){
        if(pool[2*(maze->getX()+1)][2*maze->getY()] == 0){
            int x = maze->getX()+1;
            int y = maze->getY();
            if(pool[2*x][2*y] == 0){
                pool[2*x][2*y] = 1;
                pool[(maze->getX()+x)][(maze->getY()+y)] = 1;
                Maze *next = maze->addNext(x,y);
                maze = next;
            }
        }
    }
}




