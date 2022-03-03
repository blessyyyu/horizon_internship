/*
 * @Date: 2022-03-02 14:35:12
 * @LastEditors: Cyan
 * @LastEditTime: 2022-03-03 14:15:47
 */
#include <iostream>

#include "hashtable.h"

int main() {
  // 设置size = 10;
  MyHashMap<int, int> hashmap(10);
  hashmap.set_valuenull();
  hashmap.insert(1, 2);
  hashmap.insert(5, 10);
  hashmap.print();
  std::cout << "--------------" << std::endl;
  hashmap.del(1);
  hashmap.print();
  std::cout << "find key 0 ~ 10:" << std::endl;
  for (int i = 0; i <= 10; i++) {
    std::cout << hashmap.find(i) << std::endl;
  }
  return 0;
}