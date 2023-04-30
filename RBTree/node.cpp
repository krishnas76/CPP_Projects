#include <iostream>
#include <cstring>

#include "node.h"
#include <limits.h>

using namespace std;

//constructors
Node::Node() {
  data = INT_MIN;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
  color = new char[6];
  strcpy(color,"red");
}

Node::Node(int input) {
  data = input;
  left = nullptr;
  right = nullptr;
  parent = nullptr;
  color = new char[6];
  strcpy(color,"red");
}

//functions

//destructor
Node::~Node() {
  left = nullptr;
  right = nullptr;
  parent = nullptr;
}
