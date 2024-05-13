
#include<iostream>
#include <exception>
#include "World.h"
using namespace std;



int main(int argc, char **argv) {


    unsigned int L; //num levels
    unsigned int N; //dimension of levels
    unsigned int V; // initial lives
    unsigned int coins;
    unsigned int nothing;
    unsigned int goombas;
    unsigned int koompas;
    unsigned int mushroom;

    string fileName;
    string variable;

    int i = 0; 
    while (i < argc-1) { 
        fileName = argv[i+1]; 
        i++; 
    } 
    ifstream toRead(fileName);

    int l = 0;
    while(getline(toRead, variable)){
        if(l == 0){
            L = stoul(variable, nullptr);
        }
        else if(l == 1){
            N = stoul(variable, nullptr);
        }
        else if(l == 2){
            V = stoul(variable, nullptr);
        }
        else if(l == 3){
            coins = stoul(variable, nullptr);
        }
        else if(l == 4){
            nothing = stoul(variable, nullptr);
        }
        else if(l == 5){
            goombas = stoul(variable, nullptr);
        }
        else if(l == 6){
            koompas = stoul(variable, nullptr);
        }
        else if(l == 7){
            mushroom = stoul(variable, nullptr);
        }
        else {
            cout << "Extra: " << variable << endl;
        }
        l++;

    }

    toRead.close();

    unsigned int percent = nothing+coins+goombas+koompas+mushroom;

    if (percent == 100){
        World *game = new World(L,N,V,coins,goombas,koompas,mushroom);
    }

return 0;
}