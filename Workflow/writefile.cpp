//
// Created by Boris on 07.12.2021.
//
#include "writefile.h"
#include "ConcreteBlockCreator.h"
static ConcreteBlockCreator<writefile> write("writefile");

void writefile::execute(std::list<std::string> &text, argString &arg) {
    std::ofstream Out(arg[2]);
    if(!Out.is_open()){
        //вернуть exception
    }
    for(auto& It : text){
        Out << It << std::endl;
    }
    text.clear();
}