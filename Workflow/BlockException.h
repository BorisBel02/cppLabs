//
// Created by Boris on 12.12.2021.
//

#ifndef WORKFLOW_BLOCKEXCEPTION_H
#define WORKFLOW_BLOCKEXCEPTION_H

#include <exception>
#include "Block.h"
#include <iostream>
class BlockException : public std::exception{

    void printMessage(auto* Block, std::string msg, argString inData){
        std::cout << msg << std::endl;
        std::cout << "Block type: " << decltype(*Block)() << " - " << Block->getType << std::endl;
        std::cout << "Input data: ";
        if(inData.size() > 1) {
            for (unsigned i = 1; i < inData.size(); ++i) {
                std::cout << "argument №" << i << " = " << inData[i] << ' ';
            }
            std::cout << std::endl;
        }
        else{
            std::cout << "~NONE~" << std::endl;
        }
    }
public: BlockException(auto* Block, std::string msg, argString inData){
        printMessage(Block, msg, inData);
    }
};


#endif //WORKFLOW_BLOCKEXCEPTION_H
