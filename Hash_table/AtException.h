//
// Created by Boris on 19.12.2021.
//

#ifndef HASH_TABLE_ATEXCEPTION_H
#define HASH_TABLE_ATEXCEPTION_H

#include <exception>
class AtException :public std::exception{
    const char* message;
public:
    const char * what() const noexcept override{
        return message;
    }
    AtException(const char* msg){
        message = msg;
    }
    AtException(){
        message = "ERROR";
    }
};
#endif //HASH_TABLE_ATEXCEPTION_H
