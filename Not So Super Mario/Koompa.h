#ifndef KOOMPA_H
#define KOOMPA_H

#include "Hero.h"
#include<random>

class Koompa{
    public:
    Koompa();
    ~Koompa();
    void fight(int win, Hero *hero, ofstream &myFile);
};

#endif