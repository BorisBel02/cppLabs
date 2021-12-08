//
// Created by Boris on 07.12.2021.
//
#include "readfile.h"
#include<iostream>
#include <fstream>

static ConcreteBlockCreator<readfile> read("readfile");

void readfile::execute(std::list<std::string> &text, argString& arg) {
    std::ifstream In(arg[2]);
    if(!In.is_open()){
        //вернуть exception
    }
    std::string buf;
    while(std::getline(In, buf)){
        text.push_back(buf);
    }
}

types readfile::getType(){
    return IN;
}