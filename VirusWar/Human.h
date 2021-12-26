//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_HUMAN_H
#define VIRUSWAR_HUMAN_H

#include "Player.h"
#include <iostream>

class Human :public Player{
    char virusSymbol;
    std::string action(char (&field)[10][10]) override;
    void setEnemy(char c) override;
};


#endif //VIRUSWAR_HUMAN_H
