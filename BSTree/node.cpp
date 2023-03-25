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
}

Node::Node(int input) {
  data = input;
  left = nullptr;
  right = nullptr;
}

//functions

//destructor
Node::~Node() {
  left = nullptr;
  right = nullptr;
}
