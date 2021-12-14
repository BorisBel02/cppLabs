//
// Created by Boris on 31.10.2021.
//
#include "BlockFactory.h"
#include "FactoryException.h"
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
    auto i = creators.find(params[0]);
    if(i == creators.end()){
        throw   FactoryException("Unregistered Block", params[0]);
    }
    BlockCreator* creator = i -> second;
    return creator->Create(params);
}

void BlockFactory::reg(const std::string& key, BlockCreator *creator) {
    if(creators.find(key) != creators.end()){
        //throw FactoryException("Block redefinition", key);
        int k = 1;
    }
    creators[key] = creator;
}