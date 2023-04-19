/*This program creates a Red-Black Tree
 *Author: Krishna Srikanth
 *Date: 
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "node.h"

using namespace std;

//function prototypes
void add(Node* tree, int num);
void print(Node* tree, int space);
bool search(Node* tree, int num);
Node* del(Node* tree, int num);

int main() {
  cout << "This is a Red-Black Tree." << endl;
  
  //make tree
  Node* tree = new Node();
  
  //user command loop
  while (true) {
    cout << "Type \"add\", \"read\", or \"print\". Type \"q\" to quit." << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    if (strcmp(input, "add") == 0) {
      //take in number of numbers
      int count;
      cout << "How many numbers would you like to add?" << endl;
      cin >> count;
      cin.ignore(50, '\n');
      int newnumbers[count];
      //take in numbers separated by spaces                                                  
      cout << "Enter your numbers separated by spaces: " << endl;
      for (int i = 0; i < count; i++) {
	cin >> newnumbers[i];
      }
      cin.ignore(50, '\n');
      //add all numbers to tree
      for (int i = 0; i < count; i++) {
	add(tree, newnumbers[i]);
      }
    }

    else if (strcmp(input, "read") == 0) {
      //take in number to remove
      cout << "Enter a number to remove:" << endl;
      int number;
      cin >> number;
      cin.ignore(50, '\n');
      //if number exists, remove it
      if (search(tree, number)) {
	del(tree, number);
        cout << number << " removed from tree." << endl;
      }
      //if number doesn't exist
      else {
        cout << number << " not found in tree." << endl;
      }
    }

    else if (strcmp(input, "print") == 0) {
      //print tree
      print(tree, 0);
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

void add(Node* tree, int num) {
  //if num greater than tree value
  if (num > tree->data) {
    //if no right child, make a right child
    if (tree->right == nullptr) {
      Node* node = new Node(num);
      tree->right = node;
    }
    //if there is right child, add to that child
    else {
      add(tree->right, num);
    }
  }
  //num less than or equal to tree value
  else {
    //if no left child, make a left child
    if (tree->left == nullptr) {
      Node* node = new Node(num);
      tree->left = node;
    }
    //if there is left child, add to that child
    else {
      add(tree->left, num);
    }
  }
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
