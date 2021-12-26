//
// Created by Boris on 25.12.2021.
//

#include "View.h"

void View::printFrame(char (&field)[10][10]) {
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

void View::printScore(std::pair<unsigned int, unsigned int> score) {
    std::cout << "Player 1 score: " << score.first << std::endl;
    std::cout << "Player 2 score: " << score.second << std::endl;
}

void View::printTurn(char t) {
    std::cout << t << std::endl;
}

void View::printActions(unsigned int turns) {
    std::cout << "Actions: " << 3 - turns%3 << std::endl;
}
