#include "maze.h"
#include "pool.h"

int main()
{
    system("Color 0A");
    srand(time(nullptr));
    int W = 10;
    Maze *start = new Maze(1,1,nullptr,nullptr);
    int **pool = pool_generate(W+1,1,1);
    start->m_move(start,pool,W);
}
