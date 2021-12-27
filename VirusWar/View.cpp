//
// Created by Boris on 25.12.2021.
//

#include "View.h"

void View::update() {
    std::pair<int, int> score = publisher->getScore();
    std::cout << "Player 1 score: " << score.first << std::endl;
    std::cout << "Player 2 score: " << score.second << std::endl;

    char t = publisher->getTurn();
    std::cout << t << std::endl;

    std::cout << "Actions: " << 3 - (publisher->getTurnQty())%3 << std::endl;

    char (&field)[10][10] = publisher->getField();
    for(int i = 9; i >= 0; --i){
        std::cout << i << "| ";
        for(int j = 0; j < 10; ++j){
            std::cout << field[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------" << std::endl;
    std::cout << " | ";
    for(int i = 0; i < 10; ++i){
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

