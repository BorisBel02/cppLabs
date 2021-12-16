//
// Created by Boris on 14.12.2021.
//

#ifndef WORKFLOW_FACTORYEXCEPTION_H
#define WORKFLOW_FACTORYEXCEPTION_H

#include "universalException.h"
class FactoryException :public universalException{
    const char* message;
    std::string name;
public:
    FactoryException(const char* pr, const std::string& blockName){
        message = pr;
        name = blockName;
    }
    std::string getName() const{
        return name;
    }
    const char * what() const noexcept override{
        return message;
    }
};


#endif //WORKFLOW_FACTORYEXCEPTION_H
