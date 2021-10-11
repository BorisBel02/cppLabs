//
// Created by Boris on 22.09.2021.
//

#include "Parse.h"
int Parse::getFile(char* fileNameIn){
    input.open(fileNameIn);
    if(!input.is_open()){
        return 2;
    }
    return 0;
}
int Parse::getOutFile(char* name){
    output.open(name);
    if(!output.is_open()){
        input.close();
        return 3;
    }
    return 0;
}
void Parse::readFile() {
    *count = 0;
    while(std::getline(input, str)) {
        for(char ch : str) {
            if ((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)) {
                word += ch;
            }
            else if(!word.empty()){
                words[word]++;
                word.clear();
                *count ++;
            }
        }
    }
}
void Parse::SortNPrint(){
    std::list <std::pair <double, std::string>> sList;//sort list
    std::list <std::pair <double, std::string>> :: iterator sListIt;//sort list

    std::map <std::string, int> :: iterator wordsIt;

    for(auto wordsIt = words.begin(); wordsIt != words.end(); wordsIt++){
        sList.push_front(std::make_pair(wordsIt -> second, wordsIt -> first));
    }

    sList.sort();
    for(auto sListIt = sList.rbegin(); sListIt != sList.rend(); sListIt++){
        output << sListIt->second << ';' << sListIt->first << ';' << (sListIt->first/(*count)) * 100 << '%' << std::endl;
    }
}
void Parse::master() {
    readFile();
    SortNPrint();
    input.close();
    output.close();
}
