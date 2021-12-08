//
// Created by Boris on 12.11.2021.
//

#ifndef WORKFLOW_DUMP_H
#define WORKFLOW_DUMP_H

#include "Block.h"
#include <iostream>

class dump: public Block{
    dump(argString& args){
        arg = args[2];
    }
    std::string arg;
    types getType() override{
        return INOUT;
    }
    void execute(std::list<std::string >& text) override{
        std::ofstream Out(arg);
        if(!Out.is_open()){
            //вернуть exception
        }
        for(auto const &It : text){
            Out << It << '\n';
        }
    }
};

#endif //WORKFLOW_DUMP_H
