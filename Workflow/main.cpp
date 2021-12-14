#include "Functions.h"
#include <map>
#include "universalException.h"
#include "FactoryException.h"
#include "BlockTypeCheck.h"
int main(int argc, char** argv) {

    std::vector<int> workflow;
    std::map<int, argString> Blocks;
    std::list<std::string> text;
    try {
        getInstructions(Blocks, argv[1], workflow);
    }
    catch (universalException& ex){
        std::cout << "ERROR\nWhile reading instructions:\n" << ex.getMessage() << std::endl;
        exit(1);
    }
    BlockTypeCheck check;
    for(int i = 0; i < workflow.size(); ++i){
        try {
            int id = workflow[i];
            std::string blockType = Blocks[id][0];

            auto Blck = BlockFactory::instance().create(Blocks[id]);
            if(!check.checkStatus(Blck->getType())){
                //type exception
            }
            Blck->execute(text, Blocks[id]);
            delete Blck;
        }
        catch (FactoryException& ex){
            std::cout << "ERROR\nIn Factory:\n" << ex.getMessage() << "\nBlock name: " << ex.getName() << std::endl;
            exit(2);
        }
        catch (universalException& ex){
            std::cout << "ERROR\nDuring execution:\n" << ex.getMessage() << std::endl;
            exit(3);
        }
    }


    return 0;
}
