//
// Created by Boris on 24.12.2021.
//

#ifndef VIRUSWAR_CONTROLLER_H
#define VIRUSWAR_CONTROLLER_H

#include <iostream>
#include <sstream>
#include <memory>
#include "Game.h"
#include "View.h"
#include "gameException.h"
#include "Bot.h"
#include "Human.h"
#include "PlayerFabric.h"

class Controller {
    PlayerFabric fabric;
    std::shared_ptr<Game> game;
    std::shared_ptr<View> view;

public:
    void runGame();
};


#endif //VIRUSWAR_CONTROLLER_H
