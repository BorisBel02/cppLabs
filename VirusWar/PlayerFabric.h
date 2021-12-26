//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_PLAYERFABRIC_H
#define VIRUSWAR_PLAYERFABRIC_H

#include "gameException.h"
#include <memory>
#include "Human.h"
#include "Bot.h"

class PlayerFabric {
public:
    std::shared_ptr<Player> create(std::string& type);
};


#endif //VIRUSWAR_PLAYERFABRIC_H
