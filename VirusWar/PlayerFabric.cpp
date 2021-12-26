//
// Created by Boris on 25.12.2021.
//

#include "PlayerFabric.h"


std::shared_ptr<Player> PlayerFabric::create(std::string& type) {
    if(type == "Human"){
        return std::make_shared<Human>();
    }
    else if(type == "Bot"){
        return std::make_shared<Bot>();
    }
    else{
        throw gameException("Unknown player type");
    }
}
