//
// Created by Boris on 06.12.2021.
//
#include "Functions.h"

void getInstructions(std::map<int, argString>& Blocks, std::string& in, std::vector<int>& workflow){
    std::ifstream inputFile(in);
    if(!inputFile.is_open()){
        //exception
    }

    std::list <std::string> instructions;

    std::string buf;

    while(std::getline(inputFile, buf)){
        instructions.push_back(buf);
    }

    auto endIter = instructions.end();

    auto descIter = std::find(instructions.begin(), endIter, "desc");
    auto csedIter = std::find(descIter, endIter, "csed");

    if(descIter == endIter || csedIter == endIter){
        //exception "no correct block description"
    }

    for(auto i = ++descIter; i != csedIter; ++i){
        int id;
        buf = *i;
        std::string param;
        argString parameters;
        unsigned paramNum = 0;
        for(char ch : buf){
            if(ch == ' '){
                parameters.push_back(param);
                continue;
            }
            if(ch == '='){
                id = std::stoi(buf);
                
                continue;
            }

            int chm = std::tolower(ch);
            if((chm >= 48 && chm <= 57) || (chm >= 97 && chm <= 122)){
                param.push_back(ch);
            }
        }
    }

}
