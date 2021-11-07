//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_WRITEFILE_H
#define WORKFLOW_WRITEFILE_H

#include "Block.h"
#include <fstream>

class writefile: Block{
    types getType() override{
        return OUT;
    }
    void execute(argString& params, std::string text) override{
        std::ofstream Out(params[2]);
        if(!Out.is_open()){
            //вернуть exception
        }
        std::fout << text << std::endl;
    }
};

#endif //WORKFLOW_WRITEFILE_H
