//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_BOT_H
#define VIRUSWAR_BOT_H

#include <vector>
#include "Player.h"

typedef std::pair<int, int> point;
class Bot :public Player{
    char enemySymbol;
    std::vector<point> growPopulation;
    std::vector<point> killPopulation;

    void updatePopulations(char (&field)[10][10]);
    std::string makeGrowCommand(char (&field)[10][10]);
    std::string makeKillCommand(char (&field)[10][10]);

    bool find(int x, int y, char what, char (&field)[10][10]);
    point findPoint(point p, char (&field)[10][10], char what);
public:
    std::string action(char (&field)[10][10]) override;
    void setEnemy(char c) override;
};


#endif //VIRUSWAR_BOT_H
