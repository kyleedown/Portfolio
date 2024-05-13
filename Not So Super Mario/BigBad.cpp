#include "BigBad.h"

BigBad::BigBad(){
}

BigBad::~BigBad(){}

void BigBad::fight(int win, Hero *hero, ofstream &myFile){
    int num = rand() % 100;
    bool defeat = false;
    if (num > 50) {
        defeat = true;
        win++; 
    }
    if(!defeat){
        myFile << "Mario fought the level boss and lost.\n";
        hero->powerDown();
        hero->powerDown();
        if(hero->isAlive()){
            fight(win, hero, myFile);
        }
    }
}
