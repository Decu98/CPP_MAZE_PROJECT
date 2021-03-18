#include "pool.h"

int **pool_generate(int W, int sx, int sy){
    int **pool = new int*[W*2];

    for(int i = 0; i < W*2; i++){
        pool[i] = new int[W*2];
    }
    pool[sx][sy] = 1;
    for(int i = 0; i < W*2; i++){
        for(int j = 0; j < W*2; j++){
            pool[i][j] = 0;
        }
    }
    return pool;
}
