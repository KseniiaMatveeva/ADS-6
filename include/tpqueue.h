// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
 private :
  T arr[10];
  int first, last;
 public :
  TPQueue():first(0), last(0) {}
  void push(T value) {
    if (last - first >= size) {
      throw std::string("Full");
    } else {
      if (value.prior >= arr[(last++) % size].prior) {
        arr[(last++) % size] = value;
      } else {
      int zam = last++;
        while (value.prior < arr[(zam - 1) % size].prior) {
          if (value.prior == arr[(zam) % size].prior) {
            arr[zam % size] = value;
            break;
          }
          arr[(1 + zam) % size] = arr[zam % size];
          zam--;
        }
      }
    }
  }
  T pop() {
    if (first == last) {
      throw std :: string("Empty");
    } else {
      return arr[(first++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
