#include "maze.h"

void test();

int main()
{
    //Druga wersja kreatora labiryntu
    //Uproszczona
    system("Color 0A");
    srand(time(nullptr));
    Maze *start = new Maze(1,1,nullptr,nullptr);
    start->init(start);
    //test(); //Usun komentarz by wykonac test

}

void test(){
    int a = 1;
    for(int i = 5; i < 50; i++){
        for(int j = 5; j < 50; j++){
            for(int k = 0; k < 50; k++){
                Maze *start = new Maze(1,1,nullptr,nullptr);
                start->Generate(start,i,j,k,1,1,false);
                std::cout << "Test nr." << a << " complete" <<std::endl;
                a++;
            }
        }
    }
}

