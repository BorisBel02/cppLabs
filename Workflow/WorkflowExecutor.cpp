//
// Created by Boris on 19.12.2021.
//

#include "WorkflowExecutor.h"
#include "TypeException.h"

void WorkflowExecutor::execWorkflow(std::vector<int>& workflow, std::map<int, argString>& Blocks, std::list<std::string>& text){
    for(int i = 0; i < workflow.size(); ++i) {
            int id = workflow[i];

            if (Blocks.find(id) == Blocks.end()) {
                throw TypeException("Unknown block id", id);
            }
            auto Blck = BlockFactory::instance().create(Blocks[id]);

            if (!status.checkStatus(Blck->getType())) {
                delete Blck;
                throw TypeException("Incorrect Block type", Blocks[id][0], id);
            }

            Blck->execute(text, Blocks[id]);

            delete Blck;
    }
}