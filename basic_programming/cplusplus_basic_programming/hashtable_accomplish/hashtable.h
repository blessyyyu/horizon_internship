/*
 * @Date: 2022-03-02 14:28:55
 * @LastEditors: Cyan
 * @LastEditTime: 2022-03-07 13:58:04
 */
#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <iostream>

// 拉链法实现hashmap: 数组 + 链表
template <typename KeyType, typename ValueType>
struct HashNode {
  KeyType key_;
  ValueType value_;
  HashNode* next_;
  HashNode(KeyType key, ValueType value)
      : key_(key), value_(value), next_(nullptr) {}
  ~HashNode() {}
};

// valuenull_需要在主函数中提前设置好
template <typename KeyType, typename ValueType>
class MyHashMap {
 public:
  int HashFunction(int key) { return key * 3 + 1; }

  void set_valuenull() { valuenull_ = -1; }

  MyHashMap(int size) {
    size_ = size;
    hashtable_ = new HashNode<KeyType, ValueType>*[size_];
    for (int i = 0; i < size_; i++) {
      hashtable_[i] = nullptr;
    }
  }

  ~MyHashMap() {
    for (int i = 0; i < size_; i++) {
      HashNode<KeyType, ValueType>* curnode = hashtable_[i];
      while (curnode) {
        HashNode<KeyType, ValueType>* temp = curnode;
        curnode = curnode->next_;
        delete temp;
        temp = nullptr;
      }
    }
    delete hashtable_;
    hashtable_ = nullptr;
  }

  bool Insert(KeyType key, ValueType value) {
    // 头插法
    // 求出哈希表的下标
    int table_index = HashFunction(key) % size_;
    HashNode<KeyType, ValueType>* head_node =
        new HashNode<KeyType, ValueType>(key, value);
    head_node->next_ = hashtable_[table_index];
    hashtable_[table_index] = head_node;
    return true;
  }

  ValueType Find(const KeyType& key) {
    int index = HashFunction(key) % size_;
    if (hashtable_[index] == nullptr) {
      return valuenull_;
    }
    HashNode<KeyType, ValueType>* curnode = hashtable_[index];
    while (curnode) {
      if (curnode->key_ == key) {
        return curnode->value_;
      } else {
        curnode = curnode->next_;
      }
    }
    // 没有找到返回valuenull
    return valuenull_;
  }

  bool Del(const KeyType& key) {
    int index = HashFunction(key) % size_;
    HashNode<KeyType, ValueType>* cur = hashtable_[index];
    if (cur == nullptr) return false;
    if (cur->key_ == key) {
      delete cur;
      cur = NULL;
      hashtable_[index] = NULL;
      return true;
    }

    HashNode<KeyType, ValueType>* pre = cur;
    cur = cur->next_;
    while (cur) {
      if (cur->key_ == key) {  //找到匹配的键值对了
        pre->next_ = cur->next_;
        delete cur;
        cur = nullptr;
        return true;
      } else {
        cur = cur->next_;
        pre = pre->next_;
      }
    }
    return false;
  }

  void Print() {
    for (int i = 0; i < size_; i++) {
      HashNode<KeyType, ValueType>* cur = hashtable_[i];
      while (cur) {
        std::cout << cur->value_ << " ";
        cur = cur->next_;
      }
      std::cout << "NULL" << std::endl;
    }
  }

 private:
  // 当前开辟table数组的大小
  int size_;
  HashNode<KeyType, ValueType>** hashtable_;
  ValueType valuenull_;
};

#endif  // HASH_TABLE_H_