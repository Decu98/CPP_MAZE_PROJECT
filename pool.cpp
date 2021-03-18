#include "pool.h"

int **pool_generate(int W,int H, int sx, int sy){
    int **pool = new int*[W*2];

    for(int i = 0; i < W*2; i++){
        pool[i] = new int[H*2];
    }
    pool[sx][sy] = 1;
    for(int i = 0; i < W*2; i++){
        for(int j = 0; j < H*2; j++){
            pool[i][j] = 0;
        }
    }
    return pool;
}

void save_maze(int **show, int W, int H){
    char ans;
    std::cout << "Do you want to save (yes = y, no = n): ";
    std::cin >> ans;
    while(ans != 'y' && ans != 'n'){
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Wrong anwser, do you want to save (yes = y, no = n): ";
        std::cin >> ans;
    }
    if(ans == 'y'){
        std::ofstream save;
        save.open("Maze.txt");
        if(save.is_open()){
            for(int i = 0 ; i < W*2+1; i++){
                for(int j = 0 ; j < H*2+1; j++){
                    save.width(2);
                    if(show[i][j] == 1){
                        save << ' ';
                    }else if(show[i][j] == 2){
                        save << '&';
                    }else if(show[i][j] == 3 || show[i][j] == 4){
                        save << '>';
                    }else{
                        save << '#';
                    }
                }
                save << std::endl;
            }
        }
        std::cout << "Saved!\n";
    }else if(ans == 'n'){
        std::cout << "Done!\n";
    }
}
