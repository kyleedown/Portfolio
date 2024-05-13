#ifndef BIGBAD_H
#define BIGBAD_H

#include "Hero.h"
#include<random>


class BigBad{
    public:
    BigBad();
    ~BigBad();
    void fight(int win, Hero *hero, ofstream &myFile);
   
};

#endif