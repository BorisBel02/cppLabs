//
// Created by Boris on 07.12.2021.
//
#include "readfile.h"
#include<iostream>
#include <fstream>
#include "universalException.h"

static ConcreteBlockCreator<readfile> read("readfile");

void readfile::execute(std::list<std::string> &text, argString& arg) {
    if(arg.size() != 2){
        throw universalException("Wrong arguments quantity");
    }
    std::ifstream In;
    In.open(arg[1]);
    if(!In.is_open()){
        throw universalException("Input file was not opened");
    }
    std::string buf;
    while(std::getline(In, buf)){
        text.push_back(buf);
    }
}

types readfile::getType(){
    return IN;
}