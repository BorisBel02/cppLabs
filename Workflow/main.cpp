#include "Functions.h"
#include <map>
#include "universalException.h"
#include "FactoryException.h"
#include "BlockTypeCheck.h"
#include "TypeException.h"

int main(int argc, char** argv) {

    if(argc != 2){
        std::cout << "Wrong console input" << std::endl;
        exit(5);
    }
    std::vector<int> workflow;
    std::map<int, argString> Blocks;
    std::list<std::string> text;
    try {
        getInstructions(Blocks, argv[1], workflow);
    }
    catch (universalException& ex){
        std::cout << "ERROR\nWhile reading instructions: " << ex.what() << std::endl;
        exit(1);
    }
    BlockTypeCheck check;
    for(int i = 0; i < workflow.size(); ++i){
        try {
            int id = workflow[i];

            if(Blocks.find(id) == Blocks.end()){
                throw TypeException("Unknown block id", id);
            }
            auto Blck = BlockFactory::instance().create(Blocks[id]);

            if(!check.checkStatus(Blck->getType())){
                throw TypeException("Incorrect Block type", Blocks[id][0], id);
            }

            Blck->execute(text, Blocks[id]);

            delete Blck;
        }
        catch (TypeException& ex){
            std::cout << "ERROR\nIncorrect workflow: " << ex.what();
            std::cout << "\n    Block name: " << ex.getName() << "\n    Block id: " << ex.getId() << std::endl;
            exit(4);
        }
        catch (FactoryException& ex){
            std::cout << "ERROR\nIn Factory: " << ex.what() << "\n  Block name: " << ex.getName() << std::endl;
            exit(2);
        }
        catch (universalException& ex){
            std::cout << "ERROR\nDuring execution: " << ex.what() << std::endl;
            exit(3);
        }
    }


    return 0;
}
