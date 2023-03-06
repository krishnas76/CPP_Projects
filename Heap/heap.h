#include <bits/stdc++.h>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class Heap {
 public:

  //constructors
  Heap(int i);

  //functions
  void add(int i);
  void removeMax();
  void reheap(int i);
  int removeAll();

  //variables
  int* array;
  int size;
  int count;
};

#endif
