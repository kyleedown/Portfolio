#include "Goomba.h"


Goomba::Goomba(){
}

Goomba::~Goomba(){}

void Goomba::fight(int win, Hero *hero, ofstream &myFile){
    int num = rand() % 100;
    bool defeat = false;
    if (num > 20) {
        defeat = true;
        win++;
    }

    if(!defeat){
        myFile << "Mario fought a Koompa and lost.\n";
        hero->powerDown();
        if(hero->isAlive()){
            fight(win, hero, myFile);
        }
    }

}