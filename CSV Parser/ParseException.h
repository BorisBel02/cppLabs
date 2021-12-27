//
// Created by Boris on 27.12.2021.
//

#ifndef CSV_PARSER_PARSEEXCEPTION_H
#define CSV_PARSER_PARSEEXCEPTION_H

#include <string>
#include <exception>

class ParseException :public std::exception{
    std::string message;
public:
    ParseException(std::string& msg){
        message = msg;
    }
    ParseException(){
        message = "Unknown exception";
    }
    std::string Pwhat(){
        return message;
    }
};


#endif //CSV_PARSER_PARSEEXCEPTION_H
