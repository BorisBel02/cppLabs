//
// Created by Boris on 29.09.2021.
//

#include "HashTable.h"
#include "Shuffle.h"
#include "AtException.h"

HashTable::HashTable(const HashTable& b){
    this -> table = b.table;
}
HashTable::HashTable(HashTable&& b)
        : table(b.table)
{
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
    hash %= table.size();
    return hash;
}
void HashTable::swap(const HashTable &b) {
    this -> table = b.table;
}
HashTable& HashTable::operator = (const HashTable& b){
    HashTable tmp(b);
    swap(tmp);
    return *this;
}
HashTable& HashTable::operator = (HashTable&& b){
    HashTable tmp(std::move(b));
    swap(tmp);
    return *this;
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

            if(check - 1 == table[index].size()){
                --tableSize;
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
    ++tableSize;
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
    return 0;
}
Value& HashTable::at(const Key &k) {
    unsigned index = hashFunc(k);
    //try {
        for (auto &it: table[index]) {
            if (k == it.first) {
                return it.second;
            }
        }
        throw AtException("No element with such key");

}
const Value& HashTable::at(const Key& k) const{
    unsigned index = hashFunc(k);
    //try {
        for (auto &it: table[index]) {
            if (k == it.first) {
                return it.second;
            }
        }
        throw AtException("No element with such key");

}
bool HashTable::empty() const {
    return table.empty();
}

bool operator==(const Student& a, const Student& b){
        return a.age == b.age && a.weight == b.weight;
}

bool operator==(const HashTable& a, const HashTable& b){
    for(const auto & i : a.table){
        for(const auto & j : i){
            if(b.contains(j.first)){
                return false;
            }
        }
    }
    return true;
}
bool operator!=(const HashTable& a, const HashTable& b){
    return !(a == b);
}
