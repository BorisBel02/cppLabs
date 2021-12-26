//
// Created by Boris on 25.12.2021.
//

#include "Bot.h"

bool Bot::find(int x, int y, char what, char (&field)[10][10]){
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if((x + i >= 0 && x + i < 10 && y + j >= 0 && y + j < 10) && field[x + i][y + j] == what){
                return true;
            }
        }
    }
    return false;
}
point Bot::findPoint(point p, char (&field)[10][10], char what){
    for(int i = -1; i <= 1; ++i){
        for(int j = -1; j <= 1; ++j){
            if((p.first + i >= 0 && p.first + i < 10 && p.second + j >= 0 && p.second + j < 10) && field[p.first + i][p.second + j] == what){
                p.first += i;
                p.second += j;
                return p;
            }
        }
    }
    return p;
}
void Bot::updatePopulations(char (&field)[10][10]) {
    for(int i = 0; i < growPopulation.size(); ++i){
        if(!find(growPopulation[i].first, growPopulation[i].second, '*', field) &&
        tolower(field[growPopulation[i].first][growPopulation[i].second]) != tolower(enemySymbol) ){
            growPopulation.erase(growPopulation.begin() + i);
        }
    }
    for(int i = 0; i < killPopulation.size(); ++i){
        if(!find(killPopulation[i].first, killPopulation[i].second, enemySymbol, field) &&
          tolower(field[killPopulation[i].first][killPopulation[i].second]) != tolower(enemySymbol) ){
            killPopulation.erase(killPopulation.begin() + i);
        }
    }
}
std::string Bot::makeGrowCommand(char (&field)[10][10]) {
    std::string command;
    point coord = growPopulation[rand()%growPopulation.size()];
    coord = findPoint(coord, field, '*');
    command = "grow " + std::to_string(coord.second) + ' ' + std::to_string(coord.first);
    growPopulation.emplace_back(coord);
    killPopulation.emplace_back(coord);
    return command;
}
std::string Bot::makeKillCommand(char (&field)[10][10]) {
    std::string command;
    point coord = killPopulation[rand()%killPopulation.size()];
    coord = findPoint(coord, field, enemySymbol);
    command = "kill " + std::to_string(coord.second) + ' ' + std::to_string(coord.first);
    killPopulation.emplace_back(coord);
    growPopulation.emplace_back(coord);
    return command;
}
std::string Bot::action(char (&field)[10][10]) {
    updatePopulations(field);
    if(!growPopulation.empty() && !killPopulation.empty()){
        if(rand()%2){
            return makeKillCommand(field);
        }
        else{
            return makeGrowCommand(field);
        }
    }
    else if(!growPopulation.empty()){
        return makeGrowCommand(field);
    }
    else if(!killPopulation.empty()){
        return makeKillCommand(field);
    }
    else{
        return "quit";
    }
}


void Bot::setEnemy(char c) {
    if(c == 'O'){
        point f;
        f.first = 0;
        f.second = 0;
        growPopulation.emplace_back(f);
    }
    else{
        point f;
        f.first = 9;
        f.second = 9;
        growPopulation.emplace_back(f);
    }
    enemySymbol = c;
}
