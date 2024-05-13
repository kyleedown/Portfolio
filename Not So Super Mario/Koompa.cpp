#include "Koompa.h"

Koompa::Koompa(){
}

Koompa::~Koompa(){}

void Koompa::fight(int win, Hero *hero, ofstream &myFile){
    int num = rand() % 100;
    bool defeat = false;
    if (num > 35) {
        defeat = true;
    }
    
    if(!defeat){
        myFile << "Mario fought a Koompa and lost.\n";
        hero->powerDown();
        if(hero->isAlive()){
            fight(win, hero, myFile);
        }
    }
}