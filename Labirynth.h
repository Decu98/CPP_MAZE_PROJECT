#ifndef LABIRYNTH_H
#define LABIRYNTH_H

#include <maze.h>
#include <pool.h>

using namespace std;

class Labirynth{
private:
    Maze *maze_;
    int **pool_;


public:
    Labirynth();
    int **pool_generate(int,int,int,int);
    void save_maze(int **,int,int);

};

#endif // LABIRYNTH_H
