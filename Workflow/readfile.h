//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_READFILE_H
#define WORKFLOW_READFILE_H

#include "Block.h"
#include <fstream>

class readfile: Block{
    types getType() override{
        return IN;
    }
    void execute(argString& params, std::string text) override{
        std::ifstream In(params[2]);
        if(!In.is_open()){
            //вернуть exception
        }
        while(fin.getline(In, text));
    }
};

#endif //WORKFLOW_READFILE_H
