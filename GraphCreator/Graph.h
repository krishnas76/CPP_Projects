#include <iostream>
#include <cstring>

//header guard
#ifndef GRAPH_H
#define GRAPH_H

using namespace std;

class Graph {
 public:

  //constructors
  Graph();
  
  //functions
  void addVertex(char name);
  void addEdge(char v1, char v2, int weight);
  
  //variables
  int size;
  int table[21][21];
  char* vertices;
};

#endif
