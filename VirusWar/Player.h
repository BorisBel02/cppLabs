//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_PLAYER_H
#define VIRUSWAR_PLAYER_H

#include <string>

class Player {
public:
    virtual std::string action(char (&field)[10][10]) = 0;
    virtual void setEnemy(char c) = 0;
};


#endif //VIRUSWAR_PLAYER_H
