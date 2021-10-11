//
// Created by Boris on 22.09.2021.
//

#ifndef LAB0_PARSE_H
#define LAB0_PARSE_H
#include <iostream>
#include <fstream>
#include <map>
#include <list>

class Parse {
    std::ifstream input;
    std::ofstream output;

    std::string str;
    std::string word;

    int* count;
    void readFile();
    void SortNPrint();
public:
    std::map <std::string, int> words;
    void master();
    int getFile(char*);
    int getOutFile(char*);
};


#endif //LAB0_PARSE_H
