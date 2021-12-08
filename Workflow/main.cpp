#include "Functions.h"
#include <map>
int main(int argc, char** argv) {

    std::vector<int> workflow;
    std::map<int, argString> Blocks;

    getInstructions(Blocks, reinterpret_cast<std::string &>(argv[1]), workflow);

    std::map<std::string, Block> Workers;




    return 0;
}
