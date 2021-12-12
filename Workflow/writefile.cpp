//
// Created by Boris on 07.12.2021.
//
#include "writefile.h"
#include "ConcreteBlockCreator.h"
static ConcreteBlockCreator<writefile> write("writefile");

void writefile::execute(std::list<std::string> &text, argString &arg) {
    if(arg.size() != 2){
        throw BlockException(this, "Wrong arguments quantity", arg);
    }
    std::ofstream Out(arg[1]);
    if(!Out.is_open()){
        throw BlockException(this, "Output file have not opened", arg);
    }
    for(auto& It : text){
        Out << It << std::endl;
    }
    text.clear();
}