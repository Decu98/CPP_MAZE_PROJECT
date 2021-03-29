#include "Labirynth.h"

Labirynth::Labirynth(){
    this->maze_ = new Maze(1,1,nullptr,nullptr);
    int W,H,prct,in,out;
    cout << "Set hight of maze (5,50): ";
    cin >> H;
    while(H < 5 || H > 50){
        cin.clear();
        cin.ignore();
        cout << "Wrong width, set again: ";
        cin >> H;
    }
    cout << "Set width of maze (5,50): ";
    cin >> W;
    while(W < 5 || W > 50){
        cin.clear();
        cin.ignore();
        cout << "Wrong hight, set again: ";
        cin >> W;
    }
    cout << "Set percentage of blocked maze (0-50): ";
    cin >> prct;
    while(prct < 0 || prct > 50){
    cin.clear();
    cin.clear();
    cin.ignore();
        cout << "Wrong percentage, set again: ";
        cin >> prct;
    }
    cout << "Set numbers of entrances " << "(1-" << W/5 << "): ";
    cin >> in;
    while(in < 1 || in > (W/5)){
        cin.clear();
        cin.ignore();
        cout << "Wrong numbers of entrances, set again: ";
        cin >> in;
    }
    cout << "Set numbers of exites " << "(1-" << W/5 << "): ";
    cin >> out;
    while(out < 1 || out > (W/5)){
        cin.clear();
        cin.ignore();
        cout << "Wrong numbers of exites, set again: ";
        cin >> out;
    }
    this->pool_ = this->pool_generate(W+1,H+1,this->maze_->getX(),this->maze_->getY());
    this->maze_->Generate(this->maze_,H,W,prct,in,out,this->pool_);
    this->save_maze(pool_,W,H);
    for(int i = 0; i < W*2; i++){
        delete [] pool_[i];
    }
    delete [] pool_;
}

int **Labirynth::pool_generate(int W,int H, int sx, int sy){
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

void Labirynth::save_maze(int **show, int W, int H){
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
