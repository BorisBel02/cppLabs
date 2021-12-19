//
// Created by Boris on 19.12.2021.
//

#ifndef WORKFLOW_WORKFLOWEXECUTOR_H
#define WORKFLOW_WORKFLOWEXECUTOR_H

#include "BlockTypeCheck.h"
#include "Functions.h"

class WorkflowExecutor {
BlockTypeCheck status;
public:
    void execWorkflow(std::vector<int>& workflow, std::map<int, argString>& Blocks, std::list<std::string>& text);
};


#endif //WORKFLOW_WORKFLOWEXECUTOR_H
