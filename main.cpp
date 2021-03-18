#include "maze.h"

int main()
{
    system("Color 0A");
    srand(time(nullptr));
    int const W = 11;
    Maze *start = new Maze((rand()%(W-2))+1,(rand()&(W-2))+1,nullptr,nullptr);
    start->Generate(start,W);
}
