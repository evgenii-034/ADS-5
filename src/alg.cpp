// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int prior(char ch) {
  switch (ch) {
    case '(':
      return 0;
    case ')':
      return 1;
    case '-': case '+':
      return 2;
    case '*': case '/':
      return 3;
    default:
      return -1;
  }
}
std::string infx2pstfx(std::string inf) {
  std::string w = "";
  TStack<char, 100> stack;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      if (w != "") {
        if (!((inf[i - 1] >= '0') && (inf[i - 1] <= '9'))) {
          w += ' ';
        }
      }
      w += inf[i];
      } else {
          int k = prior(inf[i]);
          bool f = false;
         if ((stack.isEmpty()) || (k > prior(stack.get()))) {
            f = true;
          }
            if (((k == 0) || f) && (k != 1)) {
              stack.push(inf[i]);
            } else {
                if (k != 1) {
                  while ((prior(stack.get()) >= k) && !(stack.isEmpty())) {
                    w += ' ';
                    w += stack.get();
                    stack.pop();
                  }
                  stack.push(inf[i]);
                } else {
                    while (prior(stack.get())) {
                      w += ' ';
                      w += stack.get();
                      stack.pop();
                    }
                    stack.pop();
                  }
              }
        }
    }
    while (!(stack.isEmpty())) {
      w += ' ';
      w += stack.get();
      stack.pop();
    }
    return w;
}
int eval(std::string pref) {
  TStack<int, 100> stack2;
  std::string s = "";
  int q = 0;
  for (int i = 0; i < pref.length(); i++) {
    if ((pref[i] >= '0') && (pref[i] <= '9')) {
    q = 1;
    s += pref[i];
    } else {
        if (q == 1) {
          stack2.push(std::stoi(s));
          q = 0;
          s = "";
        }
        if (pref[i] != ' ') {
          int x1 = stack2.get();
          stack2.pop();
          int x2 = stack2.get();
          stack2.pop();
          switch (pref[i]) {
            case '-':
              stack2.push(x2 - x1);
              break;
            case '+':
              stack2.push(x2 + x1);
              break;
            case '*':
              stack2.push(x2 * x1);
              break;
            case '/':
              stack2.push(x2 / x1);
              break;
          }
        }
      }
  }
  return stack2.get();
}
