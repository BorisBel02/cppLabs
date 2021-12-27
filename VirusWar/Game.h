//
// Created by Boris on 24.12.2021.
//

#ifndef VIRUSWAR_GAME_H
#define VIRUSWAR_GAME_H

#include "ObserverInterface.h"
#include <map>
#include <list>

class Game {
    char field[10][10];
    unsigned player1Score;
    unsigned player2Score;

    char playerTurn = 'X';
    char enemy = 'O';

    unsigned turnCounter = 0;
    unsigned filledCells = 0;

    bool find(int x, int y, char what);
    std::map<std::pair<int, int>, bool> chain;
    bool accessible(int x, int y);


    std::list<ObserverInterface*> observers;
public:
    Game();
    void killEnemy(int x, int y);
    void grow(int x, int y);
    char (&getField())[10][10] {
        return field;
    }
    auto getScore(){
        return std::make_pair(player1Score, player2Score);
    }
    char getTurn(){
        return playerTurn;
    }
    unsigned getTurnQty(){
        return turnCounter;
    }
    //Observer pattern methods:
    void reg(ObserverInterface* instance){
        observers.push_back(instance);
    }
    void notifySubscribers(){
        for(auto it : observers){
            it->update();
        }
    }

};

#endif //VIRUSWAR_GAME_H
