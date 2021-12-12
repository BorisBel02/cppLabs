//
// Created by Boris on 07.12.2021.
//
#include "readfile.h"
#include<iostream>
#include <fstream>

static ConcreteBlockCreator<readfile> read("readfile");

void readfile::execute(std::list<std::string> &text, argString& arg) {
    std::ifstream In(arg[1]);
    if(!In.is_open()){
        throw BlockException(this, "Input file was not opened", arg);
    }
    std::string buf;
    while(std::getline(In, buf)){
        text.push_back(buf);
    }
}

types readfile::getType(){
    return IN;
}