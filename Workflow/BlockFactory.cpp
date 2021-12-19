//
// Created by Boris on 31.10.2021.
//
#include "BlockFactory.h"
#include "FactoryException.h"
BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    return factory;
}

Block* BlockFactory::create(argString& params) {
    auto i = creators.find(params[0]);
    if(i == creators.end()){
        throw   FactoryException("Unregistered Block", params[0]);
    }
    BlockCreator* creator = i -> second;
    return creator->Create(params);
}

void BlockFactory::reg(const std::string& key, BlockCreator *creator) {
    if(creators.find(key) != creators.end()){
        throw FactoryException("Block redefinition", key);
        int k = 1;
    }
    creators[key] = creator;
}