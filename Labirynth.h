#ifndef LABIRYNTH_H
#define LABIRYNTH_H

#include <maze.h>
#include <pool.h>

using namespace std;

class Labirynth{
private:
    Maze *maze_;
    int **pool_, Width_, Height_, prct_, in_, out_;


public:
    Labirynth();
    ~Labirynth();
    int **pool_generate(int,int,int,int);
    void save_maze(int **,int,int);
    int setWidth();
    int setHeight();
    int setPercent();
    int setEntrance(int);
    int setExites(int);

};

#endif // LABIRYNTH_H
