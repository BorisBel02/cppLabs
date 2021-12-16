//
// Created by Boris on 16.12.2021.
//

#include "TypeException.h"

TypeException::TypeException(const char *msg, std::string &nm, int d) {
    message = msg;
    name = nm;
    id = d;
}
std::string TypeException::getName() const{
    return name;
}
int TypeException::getId() const{
    return id;
}
TypeException::TypeException(const char *msg, int d) {
    message = msg;
    id = d;
    name = "~NONE~";
}
TypeException::TypeException(const char *msg) {
    message = msg;
    id = -1;
}

const char *TypeException::what() const noexcept {
    return message;
}