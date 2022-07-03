/*
 * @Date: 2022-03-02 14:35:12
 * @LastEditors: Cyan
 * @LastEditTime: 2022-03-07 13:58:25
 */
#include <iostream>

#include "hashtable.h"

int main() {
  // 设置size = 10;
  MyHashMap<int, int> hashmap(10);
  hashmap.set_valuenull();
  hashmap.Insert(1, 2);
  hashmap.Insert(5, 10);
  hashmap.Print();
  std::cout << "--------------" << std::endl;
  hashmap.Del(1);
  hashmap.Print();
  std::cout << "find key 0 ~ 10:" << std::endl;
  for (int i = 0; i <= 10; i++) {
    std::cout << hashmap.Find(i) << std::endl;
  }
  return 0;
}