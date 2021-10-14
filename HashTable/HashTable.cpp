//
// Created by Boris on 29.09.2021.
//

#include "HashTable.h"
#include "Shuffle.h"
HashTable::HashTable(const HashTable& b)
{
    this -> tableSize = b.tableSize;
    this -> table = b.table;
}
HashTable::HashTable(HashTable&& b)
    : tableSize(b.tableSize),
      table(b.table)
{
    b.tableSize = 0;
    b.table.clear();
}
unsigned HashTable::hashFunc(const Key& key) const{
    unsigned int hash = 0;
    unsigned h = 0;
    for(char ch : key){
        char index = h xor ch;
        h = Shuffle[index];
        hash += h;
    }
    hash %= tableSize;
    return hash;
}
void HashTable::clear(){
    table.clear();
}
Value& HashTable::operator[](const Key& k){
    unsigned index = hashFunc(k);
    element::iterator it;
    for(it = table[index].begin(); it != table[index].end(); ++it){
        if(k == it->first){
            return it->second;
        }
    }
    ++it;
    table[index].emplace_back();

    return it -> second;
}
bool HashTable::erase(const Key& k){
    unsigned index = hashFunc(k);
    for(auto it = table[index].begin(); it != table[index].end(); ++it){
        if(k == it -> first){
            unsigned check = table[index].size();
            table[index].erase(it);

            if(check-- == table[index].size()){
                return true;
            }
            else{
                break;
            }
        }
    }
    return false;
}
bool HashTable::insert(const Key& k, const Value& v){
    unsigned index = hashFunc(k);
    unsigned check = table[index].size();

    table[index].emplace_back(k, v);

    if(check == table[index].size()){
        return false;
    }
    return true;
}
bool HashTable::contains(const Key& k) const{
    unsigned index = hashFunc(k);
    for(const auto & it : table[index]){
        if(k == it.first){
            return true;
        }
    }
    return false;
}
size_t HashTable::size() const {
    size_t res = 0;
    for(const auto& el : table){
        res += el.size();
    }
    return res;
}
Value& HashTable::at(const Key &k) {
    unsigned index = hashFunc(k);
    try {
        for (auto &it: table[index]) {
            if (k == it.first) {
                return it.second;
            }
        }
        throw -1;
    }
    catch(short i) {
        std::cout << "ERROR: value with such key was not found" << std::endl;
    }
}
const Value& HashTable::at(const Key& k) const{
    unsigned index = hashFunc(k);
    try {
        for (auto &it: table[index]) {
            if (k == it.first) {
                return it.second;
            }
        }
        throw -1;
    }
    catch(short i) {
        std::cout << "ERROR: value with such key was not found" << std::endl;
    }
}
bool HashTable::empty() const {
    return table.empty();
}


bool operator==(const HashTable& a, const HashTable& b){
    if(a.table.size() == b.table.size()){
        return a.table == b.table;
    }
    else{
        for(const auto & i : a.table){
            for(const auto & j : i){
                if(!b.contains(j.first)){
                    return false;
                }
            }
        }
    }
    return true;
}
bool operator!=(const HashTable& a, const HashTable& b){
    return !(a == b);
}