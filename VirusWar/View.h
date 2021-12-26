//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_VIEW_H
#define VIRUSWAR_VIEW_H

#include <iostream>

class View {
public:
    void printScore(std::pair<unsigned, unsigned> score);
    void printFrame(char (&field)[10][10]);
    void printTurn(char t);
    void printActions(unsigned turns);
};


#endif //VIRUSWAR_VIEW_H
