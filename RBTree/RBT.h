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
  void add(Node* tree, int data);
  Node* root;
  bool left;
  bool right;
  bool rl;
  bool lr;
};

#endif
