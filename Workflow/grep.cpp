//
// Created by Boris on 07.12.2021.
//
#include "ConcreteBlockCreator.h"
#include "grep.h"

static ConcreteBlockCreator<grep> grp("grep");

void grep::execute(std::list<std::string>& text, argString& arg){
    std::list<std::string> res;

    for (auto& it : text){
        std::size_t found = it.find(arg[1]);
        if(found != std::string::npos){
        res.push_back(it);
        }
    }
    text.swap(res);
}
types grep::getType(){
        return INOUT;
    }