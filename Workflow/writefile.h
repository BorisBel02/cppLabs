//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_WRITEFILE_H
#define WORKFLOW_WRITEFILE_H

#include "Block.h"
#include <fstream>
#include <iostream>

class writefile: public Block{

    types getType() override{
        return OUT;
    }
    void execute(std::list<std::string >& text, argString& arg) override;
};

#endif //WORKFLOW_WRITEFILE_H
