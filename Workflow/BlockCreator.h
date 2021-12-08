//
// Created by Boris on 01.11.2021.
//

#ifndef WORKFLOW_BLOCKCREATOR_H
#define WORKFLOW_BLOCKCREATOR_H

#include "Block.h"

class Block;

class BlockCreator{
public:
    virtual Block* Create(argString& params) const = 0;

    virtual ~BlockCreator() = default;
};
#endif //WORKFLOW_BLOCKCREATOR_H
