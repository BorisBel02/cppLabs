//
// Created by Boris on 31.10.2021.
//

#ifndef WORKFLOW_BLOCKFACTORY_H
#define WORKFLOW_BLOCKFACTORY_H

#include "BlockCreator.h"
#include <exception>
#include <map>

class BlockFactory {
    BlockFactory() = default;

    std::map<std::string, BlockCreator*> creators;
public:
    BlockFactory(BlockFactory&) = delete;
    BlockFactory(BlockFactory&&) = delete;

    static BlockFactory& instance();
    Block* create(argString& params);
    void reg(const std::string& key, BlockCreator* creator);
};


#endif //WORKFLOW_BLOCKFACTORY_H
