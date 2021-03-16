#include "pool.h"

int **pool_generate(int W, int sx, int sy){
    int **pool = new int*[W];

    for(int i = 0; i < W; i++){
        pool[i] = new int[W];
    }
    pool[sx][sy] = 1;
    for(int i = 0; i < W; i++){
        for(int j = 0; j < W; j++){
            pool[i][j] = 0;
        }
    }
    return pool;
}
