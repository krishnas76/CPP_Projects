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
  Node(char input);

  //destructor
  ~Node();
  
  //functions
  Node* getNext();
  char getData();
  void setNext(Node*);

  //variables
  char data;
  Node* next;
};

#endif
