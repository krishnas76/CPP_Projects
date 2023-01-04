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
  Node(Student*);

  //destructor
  ~Node();
  
  //functions
  Node* getNext();
  Student* getStudent();
  void setNext(Node*);

  //variables
  Student* student;
  Node* node;

};

#endif
