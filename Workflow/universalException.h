//
// Created by Boris on 13.12.2021.
//

#ifndef WORKFLOW_UNIVERSALEXCEPTION_H
#define WORKFLOW_UNIVERSALEXCEPTION_H

#include <exception>
#include <iostream>
#include "Block.h"
class universalException :public std::exception{
    const char* message;
public:
    const char * what() const noexcept override{
        return message;
    }
    universalException(const char* pr){
        message = pr;
    }
    universalException(){
        message = "Undefined error";
    }
};


#endif //WORKFLOW_UNIVERSALEXCEPTION_H
