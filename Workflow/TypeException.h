//
// Created by Boris on 16.12.2021.
//

#ifndef WORKFLOW_TYPEEXCEPTION_H
#define WORKFLOW_TYPEEXCEPTION_H

#include <exception>
#include <string>
class TypeException :public std::exception{
    const char* message;
    int id;
    std::string name;
public:
    TypeException(const char* msg, std::string& nm, int d);
    TypeException(const char *msg, int d);
    TypeException(const char *msg);
    std::string getName() const;
    int getId() const;
    const char * what() const noexcept override;
};


#endif //WORKFLOW_TYPEEXCEPTION_H
