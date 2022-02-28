#include <iostream>
#include "myvector.h"
int main()
{
  MyVector<int> test;
  for(int i = 0; i < 10; i ++){
    test.push_back(i);
  }
  test.print();
  test.clear();
  test.print();
  for (int i = 0; i < 1000; i++) {
    test.push_back(i);
  }
  test.print();
  std::cout << "访问MyVector中的下标为10的元素：" << test[10] << std::endl;
  return 0;
}
