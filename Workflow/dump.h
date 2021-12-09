//
// Created by Boris on 12.11.2021.
//

#ifndef WORKFLOW_DUMP_H
#define WORKFLOW_DUMP_H

#include "Block.h"
#include <iostream>

class dump: public Block{
    types getType() override{
        return INOUT;
    }
    void execute(std::list<std::string >& text, argString& arg) override;
};

#endif //WORKFLOW_DUMP_H
