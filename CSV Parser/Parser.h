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
inline void fillTuple(std::tuple<Args...>& t, std::stringstream& strstream, std::enable_if_t<pos == (sizeof ...(Args) - 1), void>* = nullptr){
    strstream >> std::get<pos>(t);
}

template<size_t pos, typename ...Args>
inline void fillTuple(std::tuple<Args...>& t, std::stringstream& strstream, std::enable_if_t<pos < (sizeof ...(Args) - 1), void>* = nullptr){
    strstream >> std::get<pos>(t);
    fillTuple<pos + 1, Args...>(t, strstream);
}



template<typename T>
bool convert(const std::string& column, T &t) {
    std::stringstream stringstream(column);
    stringstream >> t;
    if (stringstream.fail() || stringstream.bad()) {
        return false;
    }
    return true;
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
    usingTuple tupl;
    std::vector<usingTuple> tuplesArr;

    void read(int skip){
        std::string line;
        for(int i = 0; i < skip; ++i) {
            std::getline(*istream, line, lineDelim);
            ++currentLineNumber;
        }
        while(istream->eof()){
            /*std::getline(*istream, line, lineDelim);
            ++currentLineNumber;
            for(int i = 0; i < (sizeof ...(Args)); ++i){
                std::string str;
                std::stringstream lineStream(line);
                std::getline(lineStream, str, columnDelim);
                std::stringstream strStream(str);
                strStream >> get<i>(tupl);
            }
            tuplesArr.emplace_back(tupl);*/
            char ch;
            int i = 1;
            std::string str;
            if(ch == columnDelim){
                /*std::stringstream strStream(str);
                strStream >> std::get<i>(tupl);*/
                str.push_back(' ');
                ++i;
            }
            else if(ch == lineDelim){
                if(i + 1 != sizeof ...(Args)){
                    std::string error = "Lack of tuple elements in line: "
                            + std::to_string(currentLineNumber) + "\nin column: " + std::to_string(i);
                    throw ParseException(error);
                }
                std::stringstream strstream(str);
                fillTuple<0, Args...>(tupl, strstream);
                tuplesArr.emplace_back(tupl);
                str.clear();
                i = 0;
            }
            else if(ch == escapeSymbol){
                std::string shield;
                std::getline(*istream, shield, escapeSymbol);
                if(istream->eof()){
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
    typename std::vector<usingTuple>::iterator begin(){
        return tuplesArr.begin();
    }
    typename std::vector<usingTuple>::iterator end(){
        return tuplesArr.end();
    }
    /*class Iterator{
        usingTuple* currentEl;
    public:
        Iterator(usingTuple* first) : currentEl(first){};

        usingTuple& operator+ (int offset){
            return *(currentEl + offset);
        }
        usingTuple& operator- (int offset){
            return *(currentEl - offset);
        }

        usingTuple& operator++ (int){
            return *++currentEl;
        }
        usingTuple& operator-- (int){
            return *--currentEl;
        }
        usingTuple& operator++ (){
            return *++currentEl;
        }
        usingTuple& operator-- (){
            return *--currentEl;
        }

        bool operator!= (const Iterator& it){
            return currentEl != it.currentEl;
        }
        bool operator== (const Iterator& it){
            return currentEl == it.currentEl;
        }

        usingTuple& operator*(){
            return *currentEl;
        }


    };
    Iterator begin(){
        return tuplesArr.begin();
    }
    Iterator end(){
        return tuplesArr.end();
    }
*/
};


#endif //CSV_PARSER_PARSER_H
