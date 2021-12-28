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

template<typename T>
inline bool convert(const std::string& column, T &t) {
    std::stringstream stringstream(column);
    stringstream >> t;
    if (stringstream.fail() || stringstream.bad()) {
        return false;
    }
    return true;
}
template<>
inline bool convert(const std::string& column, std::string& t){
    t = column;
    return true;
}


template<size_t pos, typename ...Args>
inline void fillTuple(std::tuple<Args...>& t, std::vector<std::string>& vec, std::enable_if_t<pos == (sizeof ...(Args) - 1), void>* = nullptr){
    std::stringstream strstream(vec[pos]);
    strstream >> std::get<pos>(t);
}

template<size_t pos, typename ...Args>
inline void fillTuple(std::tuple<Args...>& t, std::vector<std::string>& vec, std::enable_if_t<pos < (sizeof ...(Args) - 1), void>* = nullptr){
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
    unsigned currentLineNumber = 0;
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
        unsigned currentLineNumber = 0;
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
        Iterator(std::istream* istr){
            istream = istr;
            currentLineNumber = -1;
        }
        Iterator& operator++(){
            int i = 1;
            std::string str;
            std::vector<std::string> line;
            while(true){
                char ch;
                istream->get(ch);
                if(istream->eof()){
                    istream = nullptr;
                    break;
                }
                if(ch == columnDelim){
                    line.push_back(str);
                    ++i;
                }
                else if(ch == lineDelim){
                    if(i != sizeof ...(Args)){
                        std::string error = "Lack of tuple elements in line: "
                                            + std::to_string(currentLineNumber) + "\nin column: " + std::to_string(i);
                        throw ParseException(error);
                    }

                    fillTuple<0, Args...>(tupl, line);
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
    };
    Iterator begin(){
        return Iterator(this -> istream, this -> currentLineNumber, this -> lineDelim, this -> columnDelim, this -> escapeSymbol);
    }
    Iterator end(){
        return Iterator(nullptr);
    }
};


#endif //CSV_PARSER_PARSER_H