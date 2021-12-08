//
// Created by Boris on 07.12.2021.
//
#include "sort.h"
#include "ConcreteBlockCreator.h"
static ConcreteBlockCreator<sort> srt("sort");

void sort::execute(std::list<std::string> &text, argString &arg) {
    text.sort();
}
