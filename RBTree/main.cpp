/*This program creates a Red-Black Tree
 *Author: Krishna Srikanth
 *Date: 4/30/23
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "node.h"
#include "RBT.h"
#include <fstream>

using namespace std;

//function prototypes
void print(Node* tree, int space);

int main() {
  cout << "This is a Red-Black Tree." << endl;
  
  //make tree
  RBT* tree = new RBT();
  
  //user command loop
  while (true) {
    cout << "Type \"add\", \"read\", or \"print\". Type \"q\" to quit." << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    if (strcmp(input, "add") == 0) {
      //take in number
      int number;
      cout << "Enter a number to add: " << endl;
      cin >> number;
      cin.ignore(50, '\n');
      tree->insert(number);
    }

    else if (strcmp(input, "read") == 0) {
      //take in numbers from file
      int numbers[100];
      int count = 0;
      cout << "Enter file name:" << endl;
      char filename[81];
      cin.getline(filename, 80, '\n');
      ifstream numberfile(filename);
      for (int i = 0; i < 100; i++) {
	if (numberfile.eof()) {
	  break;
	}
	numberfile >> numbers[i];
	count++;
      }
      for (int i = 0; i < count; i++) {
	if (numbers[i] > 0) {
	  tree->insert(numbers[i]);
	}
      }
    }

    else if (strcmp(input, "print") == 0) {
      //print tree
      print(tree->root, 0);
    }

    //quit
    else if (strcmp(input, "q") == 0) {
      break;
    }

    //invalid
    else {
      cout << "Invalid input." << endl;
    }
  }

  return 0;
}

void print(Node* tree, int space) {
  if (tree != nullptr) {
    //add 3 spaces and recursively call the method for the right child
    space += 3;
    print(tree->right, space);
    //print spaces
    for (int i = 0; i < space; i++) {
      cout << " ";
    }
    //print value
    cout << tree->data << " " << tree->color << endl;
    //recursively call the method for the left child
    print(tree->left, space);
  }
}

