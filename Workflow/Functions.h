//
// Created by Boris on 06.12.2021.
//

#ifndef WORKFLOW_FUNCTIONS_H
#define WORKFLOW_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConcreteBlockCreator.h"

void getInstructions(std::map<int, argString>& Blocks, char* in, std::vector<int>& workflow);

#endif //WORKFLOW_FUNCTIONS_H
