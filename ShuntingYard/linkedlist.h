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
  Node* peek();
  void enqueue(Node* node);
  Node* dequeue();

  // private:
  //variables
  Node* head;
  Node* tail;
};

#endif
