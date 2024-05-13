#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;


class Level{
    public:
    Level();
    Level(unsigned int N, int coin, int Goomba, int Koompa, int mushroom, bool final);
    ~Level();
    void setPos(int row, int col, char in);
    void printLevel(ofstream &myFile);
    void printLevel();
    void popLevel();
    void shuffle(int values[], int size);
    char getPos(int row, int col);
    double numCoin;
    double numGoomba;
    double numKoompa;
    double numMush;
    bool warp;
    char **m_level; 
    int m_levelNum;
    unsigned int K;

};

#endif