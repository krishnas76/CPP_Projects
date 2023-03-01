#include <bits/stdc++.h>
#include "heap.h"

using namespace std;

//constructors
Heap::Heap(int i) {
  count = 0;
  size = i;
  array = new int[i];
}

void Heap::add(int i) {
  if (count < size) {
    count++;
    array[count] = i;

    int num = count;
    while (num != 1 && array[num/2] < array[num]) {
      int temp = array[num/2];
      array[num/2] = array[num];
      array[num] = temp;
      num = num / 2;
    }
  }
  else {
    cout << "Heap is full" << endl;
  }
}
