//
// Created by Boris on 20.11.2021.
//

#ifndef WORKFLOW_REPLACE_H
#define WORKFLOW_REPLACE_H

#include "Block.h"

class replace: public Block{

    types getType() override;
    void execute(std::list<std::string>& text, argString& args) override;
};


#endif //WORKFLOW_REPLACE_H
