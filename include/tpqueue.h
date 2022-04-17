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
    int zam = last++;
    if (last - first < size) {
      while ((zam > first) && value.prior > arr[zam % size]) {
          arr[(zam) % size] = arr[(zam - 1) % size];
        zam--;
      }
      arr[zam % size] = value;
    }
  }
  T pop() {
      return arr[first % size];
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
