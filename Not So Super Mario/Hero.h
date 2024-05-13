#ifndef HERO_H
#define HERO_H
using namespace std;
#include <iostream>
#include <fstream>



class Hero{
    public:
        Hero();
        Hero(int V);
        ~Hero();
        void powerUp();
        void powerDown();
        int checkCoins();
        void addCoin();
        void removeLife();
        bool isAlive();
        void setLives(int lives);
        int m_lives;
        unsigned int coins;
        int powLevel;

};

#endif