//
// Created by Boris on 24.12.2021.
//

#include "Game.h"
#include "gameException.h"

Game::Game() {
    for(auto & i : field){
        for(int j = 0; j < 10; ++j){
            i[j] = '*';
        }
        i[10] = '\0';
    }
    field[0][0] = 'X';
    field[9][9] = 'O';
    player1Score = 1;
    player2Score = 1;
}
bool Game::find(int x, int y, char what){
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if((x + i >= 0 && x + i < 10 && y + j >= 0 && y + j < 10) && field[x + i][y + j] == what){
                return true;
            }
        }
    }
    return false;
}
bool Game::accessible(int x, int y) {
    if(find(x, y, playerTurn)){
        return true;
    }
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            int coord1 = x + i;
            int coord2 = y + j;
            if((coord1 >= 0 && coord1 < 10 && coord2 >= 0 && coord2 < 10) && field[x + i][y + j] == tolower(playerTurn) && (coord1 != x && coord2 != y)){
                if(accessible(x + i, y + j)){
                    return true;
                }
                continue;
            }
        }
    }
    return false;
}

void Game::grow(int x, int y) {
    if (field[x][y] == '*' && accessible(x, y)) {
        field[x][y] = playerTurn;
        ++turnCounter;
    }
    else{
        throw gameException("You can't set your virus in this cell");
     }

    if(playerTurn == 'X'){
        ++player1Score;
    }
    else{
        ++player2Score;
    }
    ++filledCells;
    if(turnCounter%3 == 0){
        char tmp = playerTurn;
        playerTurn = enemy;
        enemy = tmp;
    }
    notifySubscribers();
}

void Game::killEnemy(int x, int y) {
    if(accessible(x, y) && field[x][y] == enemy){
        field[x][y] = tolower(playerTurn);

    }
    else{
        throw gameException("You can't kill enemy virus in this cell");
    }
    if(playerTurn == 'X'){
        --player2Score;
    }
    else{
        --player1Score;
    }
    ++turnCounter;
    if(turnCounter%3 == 0){
        char tmp = playerTurn;
        playerTurn = enemy;
        enemy = tmp;
    }
    notifySubscribers();
}


