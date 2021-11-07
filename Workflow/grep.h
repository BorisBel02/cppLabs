//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_GREP_H
#define WORKFLOW_GREP_H

#include "Block.h"
#include <string>
#include <iostream>

class grep: Block{
    types getType() override{
        return INOUT;
    }
    void execute(argString& params, std::string text) override{
        std::string buf;
        size_t textSize = text.size();
        size_t stringsSize;
        while (textSize != stringsSize){
            std::getline(text, buf);
            if(buf.find(params[2]) != std::string::npos){
                std::cout << buf << endl;
            }
            stringsSize += buf.size();
        }
    }
};
#endif //WORKFLOW_GREP_H
