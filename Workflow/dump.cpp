//
// Created by Boris on 08.12.2021.
//
#include "dump.h"
#include "fstream"
#include "universalException.h"

static ConcreteBlockCreator<dump> dmp("grep");

void dump::execute(std::list<std::string >& text, argString& arg){
    if(arg.size() != 2){
        throw universalException("Wrong arguments quantity");
    }
    std::ofstream Out;
    Out.open(arg[1]);
    if(!Out.is_open()){
        throw universalException("Out file was not opened");
    }
    for(auto const &It : text){
        Out << It << '\n';
    }
}