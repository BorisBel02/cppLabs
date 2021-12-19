//
// Created by Boris on 06.12.2021.
//
#include "Functions.h"
#include <sstream>
#include "TypeException.h"

void Functions::getInstructions(std::map<int, argString>& Blocks, char* in, std::vector<int>& workflow){
    std::ifstream inputFile;
    inputFile.open(in);
    if(!inputFile.is_open()){
        throw TypeException("Instruction file was not opened");
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
            throw TypeException("No Block description in the instruction file");
        }
    }
    ++i;
    int j = i;
    while(instructions[j].find("csed") == std::string::npos){
        ++j;
        if(j >= instructions.size()){
            throw TypeException("No Block description end in the instruction file");
        }
    }
    while(instructions[i].find("csed") == std::string::npos){
        int id;
        argString parameters;
        std::stringstream line(instructions[i]);
        if(!std::getline(line, buf, '=')){
            throw TypeException("description");
        }

        id = std::stoi(buf);
        if(Blocks.find(id) != Blocks.end()){
            throw(TypeException("Id redefinition", id));
        }

        while(std::getline(line, buf, ' ')){
            if(!buf.empty()){
                parameters.push_back(buf);
            }
        }
        Blocks[id] = parameters;
        ++i;
    }
    if(i + 1 >= instructions.size()){
        throw TypeException("No workflow in the instruction file");
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

