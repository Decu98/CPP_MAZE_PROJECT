#include "maze.h"

int main()
{
    system("Color 0A");
    srand(time(nullptr));
    int const W = 10;
    Maze *start = new Maze(1,1,nullptr,nullptr);
    start->Generate(start,W);
}
