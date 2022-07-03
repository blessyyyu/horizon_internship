#include <atomic>
#include <iostream>
class SharedCount {
 public:
  SharedCount() : count_{1} {}
  void add() { ++count_; }
  void minus() { --count_; }
  int get() const { return count_; };

 private:
  std::atomic<int> count_;
};

template <typename T>
class SharedPtr {
 public:
  SharedPtr(T *ptr) : ptr_{ptr}, ref_count_{new SharedCount()} {}
  SharedPtr() : ptr_{nullptr}, ref_count_{new SharedCount()} {}
  /* 拷贝构造函数 */
  SharedPtr(const SharedPtr &p) {
    this->ptr_ = p.ptr_;
    this->ref_count_ = p.ref_count_;
    ref_count_->add();
  }
  /* 赋值构造函数 */
  SharedPtr &operator=(const SharedPtr &p) {
    clean();
    this->ptr_ = p.ptr_;
    this->ref_count_ = p.ref_count_;
    ref_count_->add();
    return *this;
  }
  /* 移动拷贝函数 */
  SharedPtr(SharedPtr &&p) {
    this->ptr_ = p.ptr_;
    this->ref_count_ = p.ref_count_;
    p.ptr_ = nullptr;
    p.ref_count_ = nullptr;
  }
  /* 移动赋值函数 */
  SharedPtr &operator=(SharedPtr &&p) {
    this->ptr_ = p.ptr_;
    this->ref_count_ = p.ref_count_;
    p.ptr_ = nullptr;
    p.ref_count_ = nullptr;
    return *this;
  }
  ~SharedPtr() { clean(); }

  /* use_count 获得引用计数 */
  int use_count() { return ref_count_->get(); }
  /* 获得指针 */
  T *get() const { return ptr_; }
  /* 获得指针内容 */
  T &operator*() const { return *ptr_; };

 private:
  /* 析构函数: 引用计数 - 1， 如果为0， 释放所有指针 */
  void clean() {
    if (ref_count_) {
      ref_count_->minus();
      if (ref_count_->get() == 0) {
        if (ptr_) delete ptr_;
        delete ref_count_;
      }
    }
  }
  T *ptr_;
  SharedCount *ref_count_;
};

struct A {
  A() { std::cout << "A() \n"; }
  ~A() { std::cout << "~A() \n"; }
};

void test_simple_shared() {
  A *a = new A;
  SharedPtr<A> ptr(a);
  {
    std::cout << ptr.use_count() << std::endl;
    SharedPtr<A> b = ptr;
    std::cout << ptr.use_count() << std::endl;
    SharedPtr<A> c = ptr;
    std::cout << ptr.use_count() << std::endl;
    SharedPtr<A> d = std::move(b);
    std::cout << ptr.use_count() << std::endl;
  }
  std::cout << ptr.use_count() << std::endl;
}

int main() {
  test_simple_shared();
  std::cout << "hello" << std::endl;
  // system("pause");
  return 0;
}