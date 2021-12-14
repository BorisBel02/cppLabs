//
// Created by Boris on 20.11.2021.
//

#include "ConcreteBlockCreator.h"
#include "replace.h"
#include "universalException.h"
static ConcreteBlockCreator<replace> rplc("replace");

void replace::execute(std::list<std::string>& text, argString& args) {
    if(args.size() != 3){
        throw universalException("Wrong arguments quantity");
    }
    if(args[1] == args[2]){
        return;
    }
    std::size_t word1Len = args[1].size();
    for(auto it = text.begin(); it != text.end(); ++it){
        while(true){
            std::size_t found = it->find(args[1]);

            if(found == std::string::npos){
                break;
            }
            it->replace(found, word1Len, args[2]);
        }
    }
}
types replace::getType(){
    return INOUT;
}