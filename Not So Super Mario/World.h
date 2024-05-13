#ifndef WORLD_H
#define WORLD_H

#include "Level.h"
#include "Hero.h"
#include "Coin.h"
#include "Mushroom.h"
#include "Goomba.h"
#include "Koompa.h"
#include "BigBad.h"
#include <time.h>
#include <iostream>
#include <fstream>

class World{
    public:
    World(unsigned int L,unsigned int N,unsigned int V,unsigned int coins,unsigned int mushroom,unsigned int goombas,unsigned int koompas);
    ~World();
    char moveHero(int level, int row, int col);
    int L; 
    Level **levels;
    Hero *mario;
    int row;
    int col;

};

#endif