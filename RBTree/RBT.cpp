#include <iostream>
#include <cstring>
#include "node.h"
#include "RBT.h"

using namespace std;

RBT::RBT() {
  root = nullptr;
}

void RBT::add(Node* tree, int data) {
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
