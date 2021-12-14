//
// Created by Boris on 07.12.2021.
//
#include "writefile.h"
#include "ConcreteBlockCreator.h"
#include "universalException.h"
static ConcreteBlockCreator<writefile> write("writefile");

void writefile::execute(std::list<std::string> &text, argString &arg) {
    if(arg.size() != 2){
        throw universalException("Wrong arguments quantity");
    }
    std::ofstream Out(arg[1]);
    if(!Out.is_open()){
        throw universalException("Output file have not opened");
    }
    for(auto& It : text){
        Out << It << std::endl;
    }
    text.clear();
}