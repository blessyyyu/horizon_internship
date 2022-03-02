/*
 * @Date: 2022-03-02 14:28:55
 * @LastEditors: Cyan
 * @LastEditTime: 2022-03-02 17:52:30
 */
#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>

template <typename KeyType, typename ValueType>
struct HashNode {
  KeyType key_;
  ValueType value_;
  HashNode* next_;
  HashNode(KeyType key, ValueType value)
      : key(key_), value(value_), next_(nullptr) {}
  ~HashNode() {}
}

template <typename KeyType, typename ValueType>
class MyHashMap {
 public:
 private:
  int size_;
  int capacity_;
  HashNode<KeyType, ValueType>** hashtable_;
  ValueType valuenull_;
}

#endif HASH_TABLE_H_