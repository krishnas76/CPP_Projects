#include <bits/stdc++.h>
#include "heap.h"

using namespace std;

//constructor
Heap::Heap(int i) {
  count = 0;
  size = i;
  array = new int[i];
}

void Heap::add(int i) {
  //if heap isn't full
  if (count < size) {
    count++;

    //temporarily set new value to the end of heap, then re-sort it
    array[count] = i;
    int num = count;
    while (num != 1 && array[num/2] < array[num]) {
      int temp = array[num/2];
      array[num/2] = array[num];
      array[num] = temp;
      num = num / 2;
    }
  }
  
  //heap is full
  else {
    cout << "Heap is full" << endl;
  }
}

int Heap::removeMax() {
  //if heap is empty
  if (count == 0) {
    return INT_MIN;
  }

  //if heap has one number
  else if (count == 1) {
    count--;
    return array[1];
  }

  //if heap has more than one number
  else {
    //set max to the max value, then remove the max and re-sort the heap
    int max = array[1];
    array[1] = array[count];
    count--;
    reheap(1);
    return max;
  }
}

void Heap::reheap(int i) {
  //setting indexes of left, right, and the current max
  int left = i * 2;
  int right = i * 2 + 1;
  int max = i;

  //if left exists and is greater than current max
  if (left < count && array[left] > array[i]) {
    max = left;
  }

  //if right exists and is greater than the current max
  if (right < count && array[right] > array[max]) {
    max = right;
  }
  
  //if the max has been modified so far
  if (max != i) {
    int temp = array[i];
    array[i] = array[max];
    array[max] = temp;
    reheap(max);
  }
}

void Heap::print(int index, int space) {
  //if index is in the heap and isn't the null value
  if (index <= count && array[index] != INT_MIN) {
    //add 3 spaces and recursively call the method for the right child
    space += 3;
    print(index * 2 + 1, space);
    //print spaces
    for (int i = 0; i < space; i++) {
      cout << " ";
    }
    //print value
    cout << array[index] << endl;
    //recursively call the method for the left child
    print(index * 2, space);
  }
}
