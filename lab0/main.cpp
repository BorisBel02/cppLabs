#include <iostream>
#include "Parse.h"

int main(int argc, char** argv) {
    if(argc != 3){
        std::cout << "bad input" << std::endl;
        return 1;
    }

    Parse Parse;

    if(Parse.getFile(argv[1])){
        std::cout << "can't open the input file";
        return 2;
    }
    if(Parse.getOutFile(argv[2])){
        std::cout << "Can't open the output file" << std::endl;
        return 3;
    }
    Parse.master();

    return 0;
}
