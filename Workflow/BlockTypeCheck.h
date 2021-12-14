//
// Created by Boris on 14.12.2021.
//

#ifndef WORKFLOW_BLOCKTYPECHECK_H
#define WORKFLOW_BLOCKTYPECHECK_H

#include "Block.h"
class BlockTypeCheck{
    bool INstat = false;
    bool OUTstat = false;
public:
    bool checkStatus(types type){
        if(type == INOUT){
            if(!INstat || OUTstat) {
                return false;
            }
            return true;
        }
        else if(type == IN){
            if(INstat){
                return false;
            }
            INstat = true;
            return true;

        }
        else if(type == OUT){
            if(OUTstat || !INstat){
                return false;
            }
            OUTstat = true;
            return true;
        }
        return false;
    }
};
#endif //WORKFLOW_BLOCKTYPECHECK_H
