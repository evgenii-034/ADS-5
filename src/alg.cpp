// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
template<typename T, int size>
class TStack {
private:
T arr[100];
  int top;
 public:
  TStack():top(-1) { }
  T get() const {
    return arr[top];
  }
  int isFull() const {
    return top == size - 1;
  }
  int isEmpty() const {
    return top == - 1;
  }
  void push(T p) {
    if (top < size - 1)
      arr[++top] = p;
  }
  void pop() {
    if (top >= 0)
      top--;
  }
};
int prior(char ch);
#endif
