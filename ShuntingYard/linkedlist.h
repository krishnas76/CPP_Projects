#include <bits/stdc++.h>
#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

class LinkedList {
 public:

  //constructors
  LinkedList();

  //functions
  void push(Node* node);
  bool pop();
  Node* peak();
  void enqueue(Node* node);
  bool dequeue();

 private:
  //variables
  Node* head;
  Node* tail;
};

#endif
