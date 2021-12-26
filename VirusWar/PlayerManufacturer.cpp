//
// Created by Boris on 25.12.2021.
//

#include "PlayerManufacturer.h"


std::shared_ptr<Player> PlayerManufacturer::create(std::string& type) {
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
