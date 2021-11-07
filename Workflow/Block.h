//
// Created by Boris on 01.11.2021.
//

#ifndef WORKFLOW_BLOCK_H
#define WORKFLOW_BLOCK_H

#include <string>
#include <vector>

enum types{
    IN,
    OUT,
    INOUT
};
typedef std::vector<std::string> argString;

class Block{
public:
    virtual void execute(argString& params, std::string text) = 0;
    virtual types getType() = 0;

    virtual ~Block() = default;
};

#endif //WORKFLOW_BLOCK_H
