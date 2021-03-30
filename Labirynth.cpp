#include "Labirynth.h"

Labirynth::Labirynth(){
    this->maze_ = new Maze(1,1,nullptr,nullptr,nullptr,nullptr,nullptr);
    int W = this->setWidth(),
        H = this->setHeight(),
        prct = this->setPercent(),
        in = this->setEntrance(W),
        out = this->setExites(W);
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
    cout << "Do you want to save (yes = y, no = n): ";
    cin >> ans;
    while(ans != 'y' && ans != 'n'){
        cin.clear();
        cin.ignore();
        cout << "Wrong anwser, do you want to save (yes = y, no = n): ";
        cin >> ans;
    }
    if(ans == 'y'){
        ofstream save;
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
                save << endl;
            }
        }
        cout << "Saved!\n";
    }else if(ans == 'n'){
        cout << "Done!\n";
    }
}

int Labirynth::setWidth(){
    cout << "Set width of maze (5,50): ";
    cin >> Width_;
    while(Width_ < 5 || Width_ > 50){
        cin.clear();
        cin.ignore();
        cout << "Wrong hight, set again: ";
        cin >> Width_;
    }
    return Width_;
}

int Labirynth::setHeight(){
    cout << "Set hight of maze (5,50): ";
    cin >> Height_;
    while(Height_ < 5 || Height_ > 50){
        cin.clear();
        cin.ignore();
        cout << "Wrong width, set again: ";
        cin >> Height_;
    }
    return Height_;
}

int Labirynth::setPercent(){
    cout << "Set percentage of blocked maze (0-50): ";
    cin >> prct_;
    while(prct_ < 0 || prct_ > 50){
    cin.clear();
    cin.clear();
    cin.ignore();
        cout << "Wrong percentage, set again: ";
        cin >> prct_;
    }
    return prct_;
}

int Labirynth::setEntrance(int W){
    cout << "Set numbers of entrances " << "(1-" << W/5 << "): ";
    cin >> in_;
    while(in_ < 1 || in_ > (W/5)){
        cin.clear();
        cin.ignore();
        cout << "Wrong numbers of entrances, set again: ";
        cin >> in_;
    }
    return in_;
}

int Labirynth::setExites(int W){
    cout << "Set numbers of exites " << "(1-" << W/5 << "): ";
    cin >> out_;
    while(out_ < 1 || out_ > (W/5)){
        cin.clear();
        cin.ignore();
        cout << "Wrong numbers of exites, set again: ";
        cin >> out_;
    }
    return out_;
}
