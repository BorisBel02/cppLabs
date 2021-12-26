//
// Created by Boris on 13.11.2021.
//

#ifndef WORKFLOW_CONCRETEBLOCKCREATOR_H
#define WORKFLOW_CONCRETEBLOCKCREATOR_H

#include "BlockCreator.h"
#include "BlockFactory.h"

template <typename T>
class ConcreteBlockCreator : public BlockCreator {
public:
    ConcreteBlockCreator(const std::string& name){
        BlockFactory::instance().reg(name, this);
    }
    Block* Create(argString& args) const override{
        return new T;
    }
};
#endif //WORKFLOW_CONCRETEBLOCKCREATOR_H
