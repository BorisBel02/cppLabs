//
// Created by Boris on 06.12.2021.
//
#include "Functions.h"
#include <sstream>
#include "universalException.h"
void getInstructions(std::map<int, argString>& Blocks, char* in, std::vector<int>& workflow){
    std::ifstream inputFile;
    inputFile.open(in);
    if(!inputFile.is_open()){
        throw universalException("Instruction file was not opened");
    }

    std::vector <std::string> instructions;

    std::string buf;

    while(std::getline(inputFile, buf)){
        instructions.emplace_back(buf);
    }

    int i = 0;
    while(instructions[i].find("desc") == std::string::npos){
        ++i;
        if(i >= instructions.size()){
            throw universalException("No Block description in the instruction file");
        }
    }
    ++i;
    while(instructions[i].find("csed") == std::string::npos){
        if(i >= instructions.size()){
            throw universalException("No description end");
        }
        int id;
        argString parameters;
        std::stringstream line(instructions[i]);
        if(!std::getline(line, buf, '=')){
            throw universalException("description");
        }
        id = std::stoi(buf);
        while(std::getline(line, buf, ' ')){
            if(!buf.empty()){
                parameters.push_back(buf);
            }
        }
        Blocks[id] = parameters;
        ++i;
    }
    if(i + 1 >= instructions.size()){
        throw universalException("No workflow in the instruction file");
    }
    std::stringstream line(instructions[i + 1]);
    while(std::getline(line, buf, ' ')){
        std::string data;
        for(char ch : buf){
            if(ch >= 48 && ch <= 57){
                data.push_back(ch);
            }
        }
        if(!data.empty()){
            workflow.emplace_back(std::stoi(data));
        }
    }
}

