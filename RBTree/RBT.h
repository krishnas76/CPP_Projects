#include <iostream>
#include <cstring>
#include "node.h"

//header guard                                                                  
#ifndef RBT_H
#define RBT_H

using namespace std;

class RBT {
 public:
  RBT();
  void insert(int data);
  Node* add(Node* tree, int data);
  Node* leftrotate(Node* node);
  Node* rightrotate(Node* node);
  Node* root;
  bool left;
  bool right;
  bool rl;
  bool lr;
};

#endif
