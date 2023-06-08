#include <iostream>
#include <cstring>
#include "Graph.h"

using namespace std;

Graph::Graph() {
  //initialize all slots of adjacency table to -1 (no edge)
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      table[i][j] = -1;
    }
  }
  vertices = new char[21];
  size = 0;
}

void Graph::addVertex(char name) {
  //add vertex to vertices list, put in a new slot in the adjacency table, and increase size by 1
  vertices[size] = name;
  table[size][size] = 0;
  size++;
}

void Graph::addEdge(char v1, char v2, int weight) {
  int v1index;
  int v2index;
  //find indices of both vertices
  for (int i = 0; i < size; i++) {
    if (vertices[i] == v1) {
      v1index = i;
    }
    else if (vertices[i] == v2) {
      v2index =	i;
    }
  }
  //update adjacency table
  table[v1index][v2index] = weight;
  table[v2index][v1index] = weight;
}
