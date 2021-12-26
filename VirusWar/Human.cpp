//
// Created by Boris on 25.12.2021.
//

#include "Human.h"

std::string Human::action(char (&field)[10][10]) {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

void Human::setEnemy(char c) {
    virusSymbol = c;
}
