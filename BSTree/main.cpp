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
