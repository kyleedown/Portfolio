
#include "Hero.h"
#include<iostream>

Hero::Hero(){
    m_lives = 5;
    powLevel = 0;
    coins = 0;
}

Hero::Hero(int V){
    m_lives = V;
    powLevel = 0;
    coins = 0;
}

Hero::~Hero(){
}

void Hero::powerUp(){
    if (powLevel == 2){
        
    }
    else{
        powLevel++;
        powLevel = 0;
    }
}

void Hero::powerDown(){
    powLevel--;
    if (powLevel < 0){
        removeLife();
        powLevel = 0;
    }
}

int Hero::checkCoins(){
    std::cout << "is this being called???" << coins << std::endl;   //////FIXME

    return coins;
}

void Hero::removeLife(){
    m_lives--;
}

bool Hero::isAlive(){
    return(m_lives > 0);
}

void Hero::addCoin(){
    if (coins == 20) {
        m_lives++;
        coins = 1;
    }
    else{
        coins++;
    }
    
}

void Hero::setLives(int lives){
    m_lives = lives;
}
