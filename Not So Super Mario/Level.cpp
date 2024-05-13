#include "Level.h"


Level::Level(){}


Level::Level(unsigned int N, int coin, int Goomba, int Koompa, int mushroom, bool final){
    K = N;             
    warp = final;
    m_level = new char*[K];
    for(int i = 0; i < K; ++i){
        m_level[i] = new char[K];
    }
    for(int i = 0; i < K; ++i){
        for(int j = 0; j< K; ++j){
            m_level[i][j] = 'x';
        }
    }

    int total = K*K;

    numCoin = total * (coin*0.01);
    numGoomba = total * (Goomba*0.01);
    numKoompa = total * (Koompa*0.01);
    numMush = total * (mushroom*0.01);

    if ((numCoin+numGoomba+numKoompa+numMush) > total){
        std::cout << "This is not working Level Creation" << std::endl;
    }

    

}

Level::~Level(){
    for(int i = 0; i < K; ++i){
            delete[] m_level[i];
    }
    delete[] m_level;
}


void Level::shuffle(int values[], int size){
    srand((int)time(NULL));
    int randval1;
    int randval2;
    int temp;

    for(int i=0;i<(size*20);++i){
        randval1 = (rand() %(size));
        randval2 = (rand() %(size));
        temp = values[randval1];
        values[randval1] = values[randval2];
        values[randval2] = temp;        
    }
}

void Level::popLevel(){

    int values[K];
    int vals[K];
    
    for(int i=0;i < K; i++){
        values[i] = i;
    }
    shuffle(values,K);
    
    for(int i=0;i < K; i++){
        vals[i] = i;
    }
    shuffle(vals,K);
    

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;

    //use the values by itterating the array
    for (int k = 0; k < K; ++k){
        for( int j = 0; j < K; ++j){
            switch (e%4)
            {
            case 0:
                if (!warp){
                    if(f<1){
                        m_level[values[k]][vals[j]] = 'w';
                        f++;
                        break;
                    }
                }
            case 1:
                if(numGoomba > b){
                    m_level[values[k]][vals[j]] = 'g';
                    b++;
                    break;
                }
                
            case 2:
                if(numKoompa > c){
                    m_level[values[k]][vals[j]] = 'k';
                    c++;
                    break;
                }
            
            case 3:
                if(g<1){
                    m_level[values[k]][vals[j]] = 'b';
                    g++;
                    break;
                }
                
            case 4:
                if(numMush > d){
                    m_level[values[k]][vals[j]] = 'm';
                    d++;
                    break;
                }
            case  5:
                if(numCoin > a){
                    m_level[values[k]][vals[j]] = 'c';
                    a++;
                    break;
                }
                
            
            default:
                e++;
                break;
            }

        }
    }


}


char Level::getPos(int row, int col){
    return (m_level[row][col]);
}

void Level::setPos(int row, int col, char in){
    m_level[row][col] = in;
}

void Level::printLevel(ofstream &myFile){
    myFile << "\n";
    for(int i = 0; i < K; ++i){
        for(int j = 0; j< K; ++j){
            myFile << m_level[i][j] << " ";
        }
        myFile << "\n";

    }
    myFile<< "\n==============";
}
