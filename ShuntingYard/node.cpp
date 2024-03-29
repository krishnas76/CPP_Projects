#include <iostream>
#include <cstring>

#include "node.h"

using namespace std;

//constructors
Node::Node() {
  data = '\0';
  next = nullptr;
  left = nullptr;
  right = nullptr;
}

Node::Node(char input) {
  data = input;
  next = nullptr;
  left = nullptr;
  right = nullptr;
}

//functions
Node* Node::getNext() {
  return next;
}

char Node::getData() {
  return data;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

//destructor
Node::~Node() {
  next = nullptr;
  left = nullptr;
  right = nullptr;
}
