//
// Created by Boris on 31.10.2021.
//
#include "BlockFactory.h"
#include "ConcreteBlockCreator.h"
#include "readfile.h"
#include "grep.h"
#include "replace.h"
#include "sort.h"
#include "writefile.h"
#include "dump.h"

BlockFactory& BlockFactory::instance() {
    static BlockFactory factory;
    /*static bool initialized = false;
    if(!initialized){
        static ConcreteBlockCreator<readfile> read;
        static ConcreteBlockCreator<grep> grp;
        static ConcreteBlockCreator<replace> rplc;
        static ConcreteBlockCreator<sort> srt;
        static ConcreteBlockCreator<writefile> write;
        static ConcreteBlockCreator<dump> dmp;

        factory.reg("readfile", &read);
        factory.reg("grep", &grp);
        factory.reg("replace", &rplc);
        factory.reg("sort", &srt);
        factory.reg("writefile", &write);
        factory.reg("dump", &dmp);
        initialized = true;
    }*/
    return factory;
}

Block* BlockFactory::create(argString& params) {
    auto i = creators.find(params[1]);
    if(i == creators.end()){
        //exception
    }
    BlockCreator* creator = i->second;
    return creator->Create(params);
}

void BlockFactory::reg(const std::string& key, BlockCreator *creator) {
    if(creators.find(key) != creators.end()){
        //exception
    }
    creators[key] = creator;
}