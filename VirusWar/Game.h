//
// Created by Boris on 24.12.2021.
//

#ifndef VIRUSWAR_GAME_H
#define VIRUSWAR_GAME_H

#include <map>

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

public:
    Game();
    void killEnemy(int x, int y);
    void grow(int x, int y);
    void setPlayer(char player){
        playerTurn = player;
    }
    unsigned getFilledCells(){
        return filledCells;
    }
    char (&getField())[10][10] {
        return field;
    }
    auto getScore(){
        return std::make_pair(player1Score, player2Score);
    }
    char getTurn(){
        return playerTurn;
    }
    void setTurn(char t){
        playerTurn = t;
    }
    unsigned getTurnQty(){
        return turnCounter;
    }
};

#endif //VIRUSWAR_GAME_H
