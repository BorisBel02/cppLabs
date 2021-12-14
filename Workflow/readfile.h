//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_READFILE_H
#define WORKFLOW_READFILE_H

#include "Block.h"
#include "ConcreteBlockCreator.h"


class readfile: public Block{

    types getType() override;
    void execute(std::list<std::string>& text, argString& arg) override;
};

#endif //WORKFLOW_READFILE_H
