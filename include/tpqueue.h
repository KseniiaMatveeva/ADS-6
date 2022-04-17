// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_


template<typename T, int size>
class TPQueue {
 private :
  T arr[10];
  int first, last;
 public :
  TPQueue():first(0), last(0) {}
  void push(T value) {
    if (last - first < size) {
      int zam = last++;
      while ((zam >= first)) {
        if (value.prior <= arr[(zam) % size].prior) {
          arr[(1 + zam) % size] = arr[zam % size];
          zam--;
          break;
        } else {
          arr[zam % size] = value;
        }
      }
    }
  }
  T pop() {
    if (!(first == last)) {
      return arr[(first++) % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
