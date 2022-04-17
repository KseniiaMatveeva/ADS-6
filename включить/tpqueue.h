// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private:
  T arr[size];
  int first, last;
 public:
  TPQueue():first(0), last(0);
  void push(T value) {
    if (last - first >= size) {
      throw std::string("Full");
    } else {
      if (value.prior >= arr[(last) % size].prior) {
        arr[(last++) % size] = value;
      } else {
        int i = last;
        while (i < first) {
          if (arr[i].prior < value.prior) {
            arr[i % size] = value;
            last++;
          }
          arr[i % size] = arr[last++ % size];
          i--;
        }
      }
    }
  }
  T pop() {
    if (first == last) {
      throw std :: string("Empty");
    } else {
      return arr[(last++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
