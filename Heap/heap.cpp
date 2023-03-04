#include <bits/stdc++.h>
#include "heap.h"

using namespace std;

//constructors
Heap::Heap(int i) {
  count = 0;
  size = i;
  array = new int[i];
  for (int a = 0; a < size; a++) {
    array[a] = INT_MIN;
  }
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

void Heap::removeMax() {
  if (count == 0) {
    cout << "Heap is empty" << endl;
  }
  else if (count == 1) {
    count--;
    array[1] = INT_MIN;
  }
  else {
    int max = array[1];
    array[1] = array[count];
    count--;
    reheap(1);
  }
}

void Heap::reheap(int i) {
  int left = i * 2;
  int right = i * 2 + 1;
  int max = i;
  if (left < count && array[left] > array[i]) {
    max = left;
  }
  if (right < count && array[right] > array[max]) {
    max = right;
  }
  //if the max has been modified so far
  if (max != i) {
    
  }
}
