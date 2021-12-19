cmake_minimum_required(VERSION 3.20)
project(Workflow)

set(CMAKE_CXX_STANDARD 20)

add_executable(Workflow main.cpp BlockFactory.cpp BlockFactory.h Block.h BlockCreator.h readfile.h writefile.h grep.h sort.h dump.h ConcreteBlockCreator.h replace.cpp replace.h Functions.cpp Functions.h readfile.cpp grep.cpp sort.cpp writefile.cpp dump.cpp BlockException.cpp BlockException.h universalException.cpp universalException.h FactoryException.h BlockTypeCheck.h TypeException.cpp TypeException.h Parser.cpp Parser.h WorkflowExecutor.cpp WorkflowExecutor.h)
