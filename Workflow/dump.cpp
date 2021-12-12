//
// Created by Boris on 08.12.2021.
//
#include "dump.h"
#include "ConcreteBlockCreator.h"
#include "fstream"

static ConcreteBlockCreator<dump> dmp("dump");

void dump::execute(std::list<std::string >& text, argString& arg){
    std::ofstream Out(arg[1]);
    if(!Out.is_open()){
        throw BlockException(this, "Out file was not opened", arg);
    }
    for(auto const &It : text){
        Out << It << '\n';
    }
}