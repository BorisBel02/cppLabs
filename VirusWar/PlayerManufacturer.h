//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_PLAYERMANUFACTURER_H
#define VIRUSWAR_PLAYERMANUFACTURER_H

#include "gameException.h"
#include <memory>
#include "Human.h"
#include "Bot.h"

class PlayerManufacturer {
public:
    std::shared_ptr<Player> create(std::string& type);
};


#endif //VIRUSWAR_PLAYERMANUFACTURER_H
