/*This program creates a Binary Search Tree
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
  cout << "This is a Binary Search Tree." << endl;
  int size;
  cout << "How many numbers would you like to enter?" << endl;
  cin >> size;
  cin.ignore(50, '\n');
  int numbers[size];
  //take in numbers separated by spaces
  cout << "Enter your numbers separated by spaces: " << endl;
  for (int i = 0; i < size; i++) {
    cin >> numbers[i];
  }
  cin.ignore(50, '\n');
  
  //make tree
  Node* tree = new Node();
  for (int i = 0; i < size; i++) {
    if (i == 0) {
      tree->data = numbers[i];
    }
    else {
      add(tree, numbers[i]);
    }
  }
  
  //user command loop
  while (true) {
    cout << "Type \"add\", \"remove\", \"print\", or \"search\". Type \"q\" to quit." << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    if (strcmp(input, "add") == 0) {
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
      for (int i = 0; i < count; i++) {
	add(tree, newnumbers[i]);
      }
    }

    else if (strcmp(input, "remove") == 0) {
      cout << "Enter a number to delete:" << endl;
      int number;
      cin >> number;
      cin.ignore(50, '\n');
      if (search(tree, number)) {
	//delete
        cout << number << " deleted from tree." << endl;
      }
      else {
        cout << number << " not found in tree." << endl;
      }
    }

    else if (strcmp(input, "print") == 0) {
      print(tree, 0);
    }

    else if (strcmp(input, "search") == 0) {
      cout << "Enter a number to search for:" << endl;
      int number;
      cin >> number;
      cin.ignore(50, '\n');
      if (search(tree, number)) {
	cout << number << " found in tree." << endl;
      }
      else {
	cout << number << " not found in tree." << endl;
      }
    }

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
  if (num > tree->data) {
    if (tree->right == nullptr) {
      Node* node = new Node(num);
      tree->right = node;
    }
    else {
      add(tree->right, num);
    }
  }
  else {
    if (tree->left == nullptr) {
      Node* node = new Node(num);
      tree->left = node;
    }
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
    cout << tree->data << endl;
    //recursively call the method for the left child
    print(tree->left, space);
  }
}

bool search(Node* tree, int num) {
  if (tree != nullptr) {
    if (tree->data == num) {
      return true;
    }
    if (num > tree->data) {
      return search(tree->right, num);
    }
    else {
      return search(tree->left, num);
    }
  }
  return false;
}

Node* del(Node* tree, int num) {
  if (tree == nullptr) {
    return tree;
  }
  if (num > tree->data) {
    tree->right = del(tree->right, num);
  }
  else if (num < tree->data) {
    tree->left = del(tree->left, num);
  }
  else {
    
  }
}
