#include "Functions.h"
#include <map>

int main(int argc, char** argv) {

    std::vector<int> workflow;
    std::map<int, argString> Blocks;
    std::list<std::string> text;
    getInstructions(Blocks, argv[1], workflow);

    for(int i = 0; i < workflow.size(); ++i){
        int id = workflow[i];
        std::string blockType = Blocks[id][0];

        auto Blck = BlockFactory::instance().create(Blocks[id]);
        Blck->execute(text, Blocks[id]);
        delete Blck;
    }


    return 0;
}
