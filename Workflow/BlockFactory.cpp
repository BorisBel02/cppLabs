//
// Created by Boris on 31.10.2021.
//
#include "BlockFactory.h"
BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    return factory;
}

Block* BlockFactory::create(argString& params) {
    auto i = creators.find(params[1]);
    if(i == creators.end()){
        //тут должен быть exception
    }
    BlockCreator* creator = i -> second;
    return creator -> Create(params);
}

