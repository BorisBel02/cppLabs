//
// Created by Boris on 25.12.2021.
//

#ifndef VIRUSWAR_GAMEEXCEPTION_H
#define VIRUSWAR_GAMEEXCEPTION_H

#include <exception>

class gameException :public std::exception{
    const char* message;
public:
    const char * what() const noexcept override{
        return message;
    }
    gameException(const char* m){
        message = m;
    }
};


#endif //VIRUSWAR_GAMEEXCEPTION_H
