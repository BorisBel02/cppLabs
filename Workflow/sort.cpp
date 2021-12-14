//
// Created by Boris on 07.12.2021.
//
#include "sort.h"
#include "ConcreteBlockCreator.h"
#include "universalException.h"

static ConcreteBlockCreator<sort> srt("sort");

void sort::execute(std::list<std::string> &text, argString &arg) {
    if(arg.size() != 1){
        throw universalException("Wrong arguments quantity");
    }
    text.sort();
}
