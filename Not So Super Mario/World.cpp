#include "World.h"


World::World(unsigned int L,unsigned int N,unsigned int V,unsigned int coins,unsigned int mushroom,unsigned int goombas,unsigned int koompas){
    levels = new Level*[L];
    ofstream MyFile("MariosJourney.txt");
    for(int i = 0; i < L; ++i){
        bool last = (i == (L-1));
        levels[i] = new Level(N,coins, goombas,koompas,mushroom, last);
        levels[i]->popLevel();
        MyFile << "Level: " << i << "\n";
        levels[i]->printLevel(MyFile);
        MyFile << "\n\n";
    }

    mario = new Hero(V);

    
    int randval1 = (rand() %(N));
    int randval2 = (rand() %(N));
    char temp;
    int level = 0;
    temp = moveHero(level, randval1,randval2);
    levels[level]->printLevel(MyFile);
    levels[level]->setPos(randval1, randval2, 'x');
    MyFile << "\n\n";

    bool winner = false;
    int consecutiveWins = 0;


    while(mario->isAlive()){

        MyFile << "Level: " << level << ". Mario is at position: (" << randval1 << ", " << randval2 << "). ";
        MyFile << "Mario is at power level " << mario->powLevel << ". ";

        if (temp == 'c'){
            Coin *c = new Coin(mario);
            delete c;
            MyFile << "\nMario collected a coin.\n";
        }
        else if (temp == 'm'){
            Mushroom *m = new Mushroom(mario);
            MyFile << "\nMario ate a mushroom.\n";
            delete m;
        }
        else if (temp == 'g'){
            Goomba *g = new Goomba();
            g->fight(consecutiveWins, mario, MyFile);
            if(mario->isAlive()){
            MyFile << "\nMario fought a Goomba and won.\n";
            }
            delete g;
        }
        else if (temp == 'k'){
            Koompa *k = new Koompa();
            k->fight(consecutiveWins, mario, MyFile);
            if(mario->isAlive()){
            MyFile << "\nMario fought a Koompa and won.\n";
            }
            delete k;
        }
        else if (temp == 'w'){
            level++;
            randval1 = (rand() %(N));
            randval2 = (rand() %(N));
            MyFile <<"\nMario warped.\n";
        }
        else if (temp == 'b'){
            BigBad *b = new BigBad();
            b->fight(consecutiveWins, mario, MyFile);
            if(mario->isAlive()){
                if(level >= L-1){
                    MyFile << "You saved the princess and beat the game! ";
                    MyFile << "Mario has " << mario->m_lives << " lives left. Mario has " << mario->coins << " coins. ";
                    mario->setLives(0);
                }
                else{
                    level++;
                    MyFile << "\nMario beat the boss.\nNextLevel!\n";
                }
                
            }
        }
        else{
            
            MyFile << "\nThis position is empty.\n";
        }

        ///percentages to choose if randval1 + 1 randval2 +1, randval1-1, or randval2-1
        int direction = rand() %4;
        switch (direction)
        {
        case 0:
            randval1+=1;
            MyFile << "Mario will move down. ";
            break;
        case 1:
            randval1-=1;
            MyFile << "Mario will move up. ";
            break;
        case 2:
            randval2+=1;
            MyFile << "Mario will move right. ";
            break;
        case 3:
            randval2 -=1;
            MyFile << "Mario will move left. ";
            break;

        
        default:
            
            break;
        }

        if (randval1 < 0){
            randval1 = N-1;
        }
        else if (randval1 > N-1){
            randval1 = 0;
        }
        if (randval2 < 0){
            randval2 = N-1;
        }
        else if (randval2 > N-1){
            randval2 = 0;
        }


        if (!winner){
            MyFile << "Mario has " << mario->m_lives << " lives left. Mario has " << mario->coins << " coins. ";
        }



        temp = moveHero(level, randval1,randval2);
        
        levels[level]->printLevel(MyFile);
        levels[level]->setPos(randval1, randval2, 'x');
        MyFile<<"\n\n";





    }

    if (!winner){
            MyFile << "GAME OVER";
            }

    



    MyFile.close();
}

World::~World(){
    for(int i = 0; i < L; ++i){
        delete levels[i];
    }
    delete[] levels;
    delete mario;
}

char World::moveHero(int level, int row, int col){ 
    char temperary = levels[level]->getPos(row, col);
    levels[level]->setPos(row, col, 'H');
    return(temperary);
}