#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

template <class T>
class MyVector {
 public:
  // 无参数的构造函数
  MyVector() : size_(0), data_(nullptr), capacity_(this->kexpandsize_) {}
  // 带参数的构造函数
  MyVector(int size, T data) {
    // 在设定的空间上再多开辟一段空间
    this->capacity_ = size + this->kexpandsize_;
    this->size_ = size;
    this->data_ = new T[size_];
    for (int i = 0; i < this->size_; i++) {
      this->data_[i] = data;
    }
  }

  // 复制构造函数
  MyVector(const MyVector& other) {
    this->size_ = other.size_;
    this->data_ = new T[this->size_ + this->kexpandsize_];
    for (int i = 0; i < this->size_; i++) {
      this->data_[i] = other.data_[i];
    }
  }

  //析构函数
  ~MyVector() {
    if (this->size_ != 0) {
      delete[] this->data_;
    }
  }

  // push_back函数
  void push_back(T element) {
    if (this->data_ == nullptr) {
      this->size_ = 1;
      this->data_ = new T[this->size_ + this->kexpandsize_];
      data_[0] = element;
    } else {
      if (this->size_ >= this->capacity_) {
        T* temp = this->data_;
        this->capacity_ = 2 * this->capacity_ + 1;
        this->data_ = new T[this->capacity_];
        int index;
        for (index = 0; index < this->size_; index++) {
          this->data_[index] = temp[index];
        }
        this->data_[index] = element;
        this->size_ += 1;
        delete[] temp;
      } else {
        this->data_[this->size_++] = element;
      }
    }
  }

  T& operator[](int index) {
    if (index >= 0 && index < this->size_) return this->data_[index];
  }

  void clear() { this->size_ = 0; }

  void print() {
    for (int i = 0; i < this->size_; i++) {
      std::cout << this->data_[i] << " ";
    }
    std::cout << std::endl;
  }

 private:
  const int kexpandsize_ = 32;
  // 当前的空间
  int size_;
  // 实际开辟的容量
  int capacity_;
  T* data_;
};

#endif  // !MY_VECTOR_H
