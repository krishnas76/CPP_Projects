#include <iostream>
#include <cstring>

#include "Node.h"

using namespace std;

//constructors
Node::Node() {
  student = new Student();
  next = NULL;
}

Node::Node(Student* newstudent) {
  student = newstudent;
  next = NULL;
}

//functions
Node* Node::getNext() {
  return next;
}

Student* Node::getStudent() {
  return student;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

//destructor
Node::~Node() {
  next = NULL;
}
