//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_VIEW_H
#define VIRUSWAR_VIEW_H

#include <iostream>
#include <memory>
#include "ObserverInterface.h"
#include "Game.h"

class View :public ObserverInterface{
    std::shared_ptr<Game> publisher;

public:
    View(std::shared_ptr<Game> p){
        publisher = p;
        publisher ->reg(this);
    };
    void update() override;

};


#endif //VIRUSWAR_VIEW_H
