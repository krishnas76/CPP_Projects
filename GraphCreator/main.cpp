/*This program creates a Graph using an adjacency table
 *Author: Krishna Srikanth
 *Date: 6/7/23
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <iomanip>
#include <algorithm>
#include "Graph.h"

using namespace std;

int main() {
  //make graph
  Graph* graph = new Graph();

  //user loop
  while (true) {
    cout << "Would you like to add or remove vertices/edges? Type \"add\", \"remove\", or q to quit" << endl;
    cout << "Type \"print\" to print" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //print for testing
    if (strcmp(input, "print") == 0) {
      cout << "   ";
      for (int i = 0; i < graph->size; i++) {
	cout << graph->vertices[i] << "  ";
      }
      cout << endl;
      
      for (int i = 0; i < graph->size; i++) {
	cout <<	graph->vertices[i] << "  ";
	for (int j = 0; j < graph->size; j++) {
	  cout << graph->table[i][j] << "  ";
	}
	cout << endl;
      }
    }
    
    else if (strcmp(input, "add") == 0) {
      cout << "What would you like to add? Type \"edge\" or \"vertex\"" << endl;
      char item[81];
      cin.getline(item, 80, '\n'); //take in user command
      if (strcmp(item, "edge") == 0) {
	//add edge
	if (graph->size < 2) {
	  cout << "You need at least 2 vertices to make an edge" << endl;
	}
	else {
	  //take in vertices and weight
	  cout << "Enter the two vertices you would like to connect and the weight of the edge." << endl;
	  char v1;
	  cout << "First vertex:" << endl;
	  cin >> v1;
	  cin.ignore(50, '\n');
	  char v2;
          cout << "Second vertex:" << endl;
          cin >> v2;
          cin.ignore(50, '\n');
	  int weight;
	  cout << "Weight:" << endl;
	  cin >> weight;
	  cin.ignore(50, '\n');
	  //see if both vertices exist
	  bool v1exists = false;
	  bool v2exists = false;
	  for (int i = 0; i < graph->size; i++) {
	    if (graph->vertices[i] == v1) {
	      v1exists = true;
	    }
	    else if (graph->vertices[i] == v2) {
	      v2exists = true;
            }
	  }
	  //if vertices exist, make an edge between them
	  if (v1exists && v2exists) {
	    graph->addEdge(v1, v2, weight);
	  }
	  else {
	    cout << "Those vertices don't exist." << endl;
	  }
	}
      }
      else if (strcmp(item, "vertex") == 0) {
	//add vertex
	char name;
	cout << "Type a one letter name:" << endl;
	cin >> name;
	cin.ignore(50, '\n');
	graph->addVertex(name);
      }
      else {
	cout << "Invalid input." << endl;
      }
    }
    else if (strcmp(input, "remove") == 0) {
      cout << "What would you like to remove? Type \"edge\" or \"vertex\"" << endl;
      char item[81];
      cin.getline(item, 80, '\n'); //take in user command                                                        
      if (strcmp(item, "edge") == 0) {
	//remove edge
      }
      else if (strcmp(item, "vertex") == 0) {
	//remove vertex
      }
      else {
	cout <<	"Invalid input." << endl;
      }
    }
    else if (strcmp(input, "q") == 0) {
      break;
    }
    else {
      cout << "Invalid input." << endl;
    }
  }
  return 0;
}
