#include "Functions.h"
#include <map>
#include "universalException.h"
#include "FactoryException.h"
#include "WorkflowExecutor.h"
#include "TypeException.h"

int main(int argc, char** argv) {

    if(argc != 2){
        std::cerr << "Wrong console input" << std::endl;
        exit(5);
    }
    std::vector<int> workflow;
    std::map<int, argString> Blocks;
    std::list<std::string> text;

    Functions Parser;
    try {
        Parser.getInstructions(Blocks, argv[1], workflow);
    }
    catch (const TypeException& ex){
        std::cerr << "ERROR\nWhile reading instructions: " << ex.what() << std::endl;
        if(ex.getId() != - 1){
            std::cerr << "    id:" << ex.getId() << std::endl;
        }
        exit(1);
    }
    catch (const std::exception& ex){
        std::cerr << "ERROR\n" << "in " << ex.what()  << ":\n    " << typeid(ex).name() << std::endl;
        exit(5);
    }

    WorkflowExecutor exec;
    try{
        exec.execWorkflow(workflow, Blocks, text);
    }
    catch (const TypeException& ex){
        std::cerr << "ERROR\nIncorrect workflow: " << ex.what();
        std::cerr << "\n    Block name: " << ex.getName() << "\n    Block id: " << ex.getId() << std::endl;
        exit(4);
    }
    catch (const FactoryException& ex){
        std::cerr << "ERROR\nIn Factory: " << ex.what() << "\n  Block name: " << ex.getName() << std::endl;
        exit(2);
    }
    catch (const universalException& ex){
        std::cerr << "ERROR\nDuring execution: " << ex.what() << std::endl;
        exit(3);
    }
    catch (const std::exception& ex){
        std::cerr << "ERROR\n" << "in" << ex.what()  << "\n    " << typeid(ex).name() << std::endl;
        exit(5);
    }

    return 0;
}
