//
// Created by Boris on 26.12.2021.
//

#ifndef CSV_PARSER_PARSER_H
#define CSV_PARSER_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <sstream>
#include <exception>
#include <vector>
#include "ParseException.h"

template<size_t pos, typename ...Args>
inline bool convert(const std::vector<std::string>& column, std::tuple<Args...> &t) {
    std::stringstream stringstream(column[pos]);
    stringstream >> std::get<pos>(t);
    if (stringstream.fail() || stringstream.bad()) {
        return false;
    }
    return true;
}



template<size_t pos, typename ...Args>
inline void fillTuple(std::tuple<Args...>& t, std::vector<std::string>& vec, std::enable_if_t<pos == (sizeof ...(Args) - 1), void>* = nullptr){
    if(!convert<pos, Args...>(vec, t)){
        std::string error = "can not convert in column: " + std::to_string(pos);
        throw ParseException(error);
    }
    std::stringstream strstream(vec[pos]);
    strstream >> std::get<pos>(t);
}

template<size_t pos, typename ...Args>
inline void fillTuple(std::tuple<Args...>& t, std::vector<std::string>& vec, std::enable_if_t<pos < (sizeof ...(Args) - 1), void>* = nullptr){
    convert<pos, Args...>(vec, t);
    std::stringstream strstream(vec[pos]);
    strstream >> std::get<pos>(t);
    fillTuple<pos + 1, Args...>(t, vec);
}





template<typename ...Args>
class Parser {
public:
    typedef std::tuple<Args...> usingTuple;

private:
    std::istream* istream;
    int currentLineNumber = 0;
    char lineDelim = '\n';
    char columnDelim = ',';
    char escapeSymbol = '"';

    void read(int skip) {
        std::string line;
        for (int i = 0; i < skip; ++i) {
            std::getline(*istream, line, lineDelim);
            ++currentLineNumber;
        }
    }

public:
    Parser(std::istream& in, char lD, char cD, char eS, int skip){
        istream = &in;
        lineDelim = lD;
        columnDelim = cD;
        escapeSymbol = eS;
        read(skip);
    }
    Parser(std::istream& in, int skip){
        istream = &in;
        read(skip);
    }
    class Iterator{
        std::istream* istream;
        int currentLineNumber = 0;
        char lineDelim = '\n';
        char columnDelim = ',';
        char escapeSymbol = '"';
        usingTuple tupl;

    public:
        Iterator(std::istream* istr, unsigned cL, char lD, char cD, char eS){
            currentLineNumber = cL;
            istream = istr;
            lineDelim = lD;
            columnDelim = cD;
            escapeSymbol = eS;
        }
        Iterator(std::istream* istr, unsigned cL){
            istream = istr;
            currentLineNumber = cL;
        }
        Iterator& operator++(){
            int i = 1;
            std::string str;
            std::vector<std::string> line;
            while(istream -> good()){
                char ch;

                istream->get(ch);
                if(ch == EOF){
                    istream == nullptr;
                    currentLineNumber = -1;
                    break;
                }
                if(ch == columnDelim){
                    line.push_back(str);
                    str.clear();
                    ++i;
                }
                else if(ch == lineDelim){
                    line.push_back(str);
                    if(i != sizeof ...(Args)){
                        std::string error = "Lack of tuple elements in line: "
                                            + std::to_string(currentLineNumber) + "\nin column: " + std::to_string(i);
                        throw ParseException(error);
                    }
                    try {
                        fillTuple<0, Args...>(tupl, line);
                    }
                    catch(ParseException& ex){
                        std::string error = ex.Pwhat() + " in line: " + std::to_string(currentLineNumber);
                        throw ParseException(error);
                    }
                    ++currentLineNumber;
                    break;
                }
                else if(ch == escapeSymbol){
                    std::string shield;
                    std::getline(*istream, shield, escapeSymbol);
                    if(!istream->eof()){
                        std::string error = "No escape symbol in line: "
                                            + std::to_string(currentLineNumber) + "\nin column: " + std::to_string(i);
                        throw ParseException(error);
                    }
                    std::cout << shield << std::endl;
                }
                else {
                    str.push_back(ch);
                }
            }
            return *this;
        }

        Iterator& operator++(int){
            Iterator tmp(*this);
            ++(*this);
            return this;
        }
        usingTuple const &operator*()const{
            return tupl;
        }
        usingTuple const *operator->()const{
            return &tupl;
        }
        bool operator==(Iterator& other){
            return (this->istream==other->istream && this->currentLineNumber == other->currentLineNumber);
        }
        bool operator!=(Iterator& other){
            return !(this == &other);
        }
        usingTuple operator*(){
            return tupl;
        }
    };
    Iterator begin(){
        return ++Iterator(this -> istream, this -> currentLineNumber, this -> lineDelim, this -> columnDelim, this -> escapeSymbol);
    }
    Iterator end(){
        return Iterator(nullptr, -1);
    }
};


#endif //CSV_PARSER_PARSER_H