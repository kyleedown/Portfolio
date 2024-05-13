#ifndef GOOMBA_H
#define GOOMBA_H

#include "Hero.h"
#include<random>

class Goomba{
    public:
    Goomba();
    ~Goomba();
    void fight(int win, Hero *hero, ofstream &myFile);
    
    
    
};

#endif