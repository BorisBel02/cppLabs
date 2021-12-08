//
// Created by Boris on 07.11.2021.
//

#ifndef WORKFLOW_SORT_H
#define WORKFLOW_SORT_H

#include "Block.h"
class sort: public Block{
    types getType() override{
        return INOUT;
    }

    void execute(std::list<std::string>& text,argString& arg) override;
};


#endif //WORKFLOW_SORT_H
