#include <gtest/gtest.h>
#include <iostream>
#include "HashTable.h"


class HashTableTest : public ::testing::Test {
protected:
    HashTable hashTable1;
    HashTable hashTable2;
};

TEST_F(HashTableTest, dummyTest) {
    hashTable1.insert("aboba", Value());
    ASSERT_EQ(hashTable1.size(), 1) << "Check for size() func";
}

TEST_F(HashTableTest, testInsert) {
    hashTable1.clear();
    hashTable1.insert("Key 1", Value());
    hashTable1.insert("Key 2", Value());
    hashTable1.insert("Key 3", Value());
    ASSERT_EQ(hashTable1.size(), 3) << "Test size after inserting";
}

TEST_F(HashTableTest, testDeepCopy) {
    hashTable1.insert("Key 1", Value());
    hashTable1.insert("Key 2", Value());

    hashTable2 = hashTable1;

    hashTable1.clear();

    ASSERT_TRUE(hashTable1.empty()) <<"Test for deep copy";
    ASSERT_FALSE(hashTable2.empty());
}

TEST_F(HashTableTest, testContain){
    hashTable1.insert("Key 1", Value());
    ASSERT_TRUE(hashTable1.contains("Key 1"))<<"Check for erase function";
}



TEST_F(HashTableTest, testErase){
    hashTable1.insert("Key 1", Value());
    hashTable1.insert("Key 2", Value());
    hashTable1.insert("Key 3", Value());
    hashTable1.erase("Key 1");
    ASSERT_FALSE(hashTable1.contains("Hello"))<<"Check for erase function";


}

TEST_F(HashTableTest, testAts){
    hashTable1.insert("Key 1", Value());
    hashTable1.at("Key 1");
    ASSERT_TRUE(hashTable1.contains("Key 1"));
}
TEST_F(HashTableTest, testOperators){
    Value value = Value();
    value.age=18;
    value.weight=75;
    hashTable1.insert("Key 1", value);
    ASSERT_EQ((hashTable1)["Key 1"], value);
    ASSERT_EQ((hashTable1)["Key"], Value());
}
TEST_F(HashTableTest, testOperatorEquality){
    Value value = Value();
    value.age=18;
    value.weight=75;
    hashTable1.insert("Key 1", value);
    hashTable2.insert("Key 1", value);
    ASSERT_TRUE(hashTable1 == hashTable2);
}
TEST_F(HashTableTest, testSwap){
    Value value1 = Value();
    Value value2 = Value();
    value2.age=20;
    value2.weight=200;
    value1.age=6;
    value1.weight=1;
    hashTable1.insert("Key1", value1);
    hashTable2.insert("Key2", value2);
    hashTable1.swap(hashTable2);
    ASSERT_TRUE(hashTable1.contains("Key2"));
    ASSERT_FALSE(hashTable1.contains("Key1"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
