/*This program creates a Binary Search Tree
 *Author: Krishna Srikanth
 *Date: 3/22/23
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
  //take in number of numbers
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

    else if (strcmp(input, "remove") == 0) {
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

    else if (strcmp(input, "search") == 0) {
      //take in number to search
      cout << "Enter a number to search for:" << endl;
      int number;
      cin >> number;
      cin.ignore(50, '\n');
      //if number found
      if (search(tree, number)) {
	cout << number << " found in tree." << endl;
      }
      //number not found
      else {
	cout << number << " not found in tree." << endl;
      }
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
    cout << tree->data << endl;
    //recursively call the method for the left child
    print(tree->left, space);
  }
}

bool search(Node* tree, int num) {
  if (tree != nullptr) {
    //if number found, return true
    if (tree->data == num) {
      return true;
    }
    //if number greater than tree data, search in right child
    if (num > tree->data) {
      return search(tree->right, num);
    }
    //if number less than or equal to tree data, search in left child
    else {
      return search(tree->left, num);
    }
  }
  return false;
}

Node* del(Node* tree, int num) {
  //if null, return tree
  if (tree == nullptr) {
    return tree;
  }
  //if number greater than tree data, look to delete in right child
  if (num > tree->data) {
    tree->right = del(tree->right, num);
  }
  //if number less than tree data, look to delete in left child
  else if (num < tree->data) {
    tree->left = del(tree->left, num);
  }
  //number is equal to data, delete this node
  else {
    //if node has no child
    if (tree->left == nullptr && tree->right == nullptr) {
      return nullptr;
    }
    //if node only has left child
    else if (tree->right == nullptr) {
      Node* temp = tree->left;
      delete tree;
      return temp;
    }
    //if node only has right child
    else if (tree->left == nullptr) {
      Node* temp = tree->right;
      delete tree;
      return temp;
    }
    //node has left and right child
    Node* temp = tree->right;
    //find the node with the next greatest number
    while (temp->left != nullptr) {
      temp = temp->left;
    }
    //set tree data to that new number
    tree->data = temp->data;
    //delete the node with the next greatest number
    tree->right = del(tree->right, temp->data);
  }
  return tree;
}
