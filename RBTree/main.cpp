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
#include <fstream>

using namespace std;

//function prototypes
Node* add(Node* tree, Node* root, int num, bool right, bool left, bool rl, bool lr);
void print(Node* tree, int space);
bool search(Node* tree, int num);
Node* del(Node* tree, int num);
Node* leftrotate(Node* node);
Node* rightrotate(Node* node);

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
      //take in number
      int number;
      cout << "Enter a number to add: " << endl;
      cin >> number;
      cin.ignore(50, '\n');
      //if tree is empty                                                                            
      if (tree->data == INT_MIN) {
	tree->data = number;
	strcpy(tree->color, "black");
      }
      else {
	tree = add(tree, tree, number, false, false, false, false);
      }
    }
      //add all numbers to tree
      add(tree, number);
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
	if (tree->data == INT_MIN) {
	  tree->data = number;
	  strcpy(tree->color, "black");
	}
	else {
	  tree = add(tree, tree, number, false, false, false, false);
	}
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

Node* add(Node* tree, Node* root, int num, bool right, bool left, bool rl, bool lr) {
  bool 2red = false;
  if (tree == nullptr) {
    return (new Node(num));
  }
  //if num greater than or equal to tree value
  else if (num >= tree->data) {
    tree->right = add(tree->right, root, num, right, left, rl, lr);
    tree->right->parent = tree;
    if (tree != root) {
      if (strcmp(tree->color, "red") == 0 && strcmp(tree->right->color, "red") == 0) {
	2red = true;
      }
    }
  }
  //num less than tree value
  else {
    tree->left = add(tree->left, root, num, right, left, rl, lr);
    tree->left->parent = tree;
    if (tree != root) {
      if (strcmp(tree->color, "red") == 0 && strcmp(tree->left->color, "red") == 0) {
	2red = true;
      }
    }
  }
  //rotations
  if (right) {
    tree = rightrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->right->color, "red");
    right = false;
  }
  if (left) {
    tree = leftrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->left->color, "red");
    left = false;
  }
  if (rl) {
    tree->right = rightrotate(tree->right);
    tree->right->parent = tree;
    tree = leftrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->left->color, "red");
    rl = false;
  }
  if (lr) {
    tree->left = leftrotate(tree->left);
    tree->left->parent = tree;
    tree = rightrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->right->color, "red");
    lr = false;
  }
  //2 reds case
  if (2red) {
    //if current node is a right child
    if (tree->parent->right == tree) {
      //if sibling is black
      if (tree->parent->left == nullptr || strcmp(tree->parent->left->color, "black") == 0) {
	//if left child is red
	if (tree->left != nullptr && strcmp(tree->left->color, "red") == 0) {
	  rl = true;
	}
	//if right child is red
	else if (tree->right != nullptr && strcmp(tree->right->color, "red") == 0) {
	  left = true;
	}
      }
      //if sibling is red
      else {
	strcpy(tree->parent->left->color, "black");
	strcpy(tree->color, "black");
	if(root.parent!=this.root)
	  root.parent.colour = 'R';
      }
    }
    //if current node is a left child
    else {

    }
    2red = false;
  }
  return tree;
}

Node* leftrotate(Node* node) {
  Node* right = node->right;
  Node* lright = right->left;
  right->left = node;
  node->right = lright;
  node->parent = right;
  if (lright != nullptr) {
    lright->parent = node;
  }
  return right;
}

Node* rightrotate(Node* node) {
  Node* left = node->left;
  Node* rleft = left->right;
  left->right = node;
  node->left = rleft;
  node->parent = left;
  if (rleft != nullptr) {
    rleft->parent = node;
  }
  return left;
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
