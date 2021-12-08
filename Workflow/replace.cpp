//
// Created by Boris on 20.11.2021.
//

#include "ConcreteBlockCreator.h"
#include "replace.h"

static ConcreteBlockCreator<replace> rplc("replace");

void replace::execute(std::list<std::string>& text, argString& args) {
    if(args[2] == args[3]){
        return;
    }

    for(auto it = text.begin(); it != text.end(); ++it){
        while(true){
            std::size_t found = it->find(args[2]);
            std::size_t word1Len = args[2].size();
            if(found == std::string::npos){
                break;
            }
            it->replace(found, word1Len, args[3]);
        }
    }
}
types replace::getType(){
    return INOUT;
}