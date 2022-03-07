/*
 * @Date: 2022-02-28 17:23:33
 * @LastEditors: Cyan
 * @LastEditTime: 2022-03-07 13:55:26
 */
#ifndef MY_LIST_H
#define MY_LIST_H

// 要用C++17 标准实现
#include <iostream>
#include <string>
#include <variant>
#include <vector>

using T = std::variant<std::string, const char*, bool, char, unsigned char, int,
                       size_t, float, double>;

class MyList {
 public:
  // 默认的构造函数
  MyList() { std::vector<T> list_; }
  // 带参数的构造函数
  MyList(const T& var) { this->list_.push_back(var); }
  // 带多个参数的构造函数
  MyList(const std::initializer_list<T>& lst) {
    this->list_.resize(lst.size());
    std::copy(lst.begin(), lst.end(), this->list_.begin());
  }

  ~MyList() {}
  // append函数以及它的重载
  void append(const T& var) { this->list_.push_back(var); }
  // 这里append一个数组，是把它的所有元素拿出来append进去，而不是像list那样append一个数组进去
  void append(const std::vector<T>& values) {
    for (auto i = values.begin(); i != values.end(); i++) {
      this->list_.push_back(*i);
    }
  }

  void append(const std::initializer_list<T>& values) {
    for (auto i = values.begin(); i != values.end(); i++) {
      this->list_.push_back(*i);
    }
  }

  // 单个元素做类型推断再输出
  void base_print(const T& var) {
    std::visit(
        [&](const auto& arg) {
          using Ttype = typename std::decay<decltype(arg)>::type;
          using Ctype = typename std::decay<const char*>::type;
          constexpr bool b = std::is_same_v<Ttype, std::string>;
          // 如果推断出来是string或者const char* 类型
          if constexpr (b || std::is_same_v<Ttype, Ctype>) {
            auto s = std::string(arg);
            if (s.size()) std::cout << "'" << s << "'";
          } else {
            // 否则可以直接输出
            std::cout << arg;
          }
        },
        var);
  }

  void print_vector() {
    std::cout << "[";
    int n = this->list_.size();
    int i = 0;

    for (auto it = this->list_.begin(); it != this->list_.end(); it++, i++) {
      std::visit(
          [&](const auto& arg) {
            base_print(arg);
            if (i < n - 1) std::cout << ",";
          },
          *it);
    }
    std::cout << "]" << std::endl;
  }

 private:
  std::vector<T> list_;
};

#endif  // !MY_LIST_H
