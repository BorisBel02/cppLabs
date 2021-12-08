//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_GREP_H
#define WORKFLOW_GREP_H

#include "Block.h"
#include <string>
#include <iostream>

class grep: public Block{

    types getType();
    void execute(std::list<std::string>& text, argString& arg) override;
};
#endif //WORKFLOW_GREP_H
