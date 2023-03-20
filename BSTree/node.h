#include <iostream>
#include <cstring>

//header guard
#ifndef NODE_H
#define NODE_H

using namespace std;

class Node {
 public:

  //constructors
  Node();
  Node(int input);

  //destructor
  ~Node();
  
  //functions

  //variables
  int data;
  Node* left;
  Node* right;
};

#endif
