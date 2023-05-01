#include <iostream>
#include <cstring>
#include "node.h"
#include "RBT.h"

using namespace std;

RBT::RBT() {
  root = nullptr;
  right = false;
  left = false;
  rl = false;
  lr = false;
}

void RBT::insert(int data) {
  if (root == nullptr) {
    root = new Node(data);
    strcpy(root->color, "black");
  }
  else {
    root = add(root, data);
  }
}

Node* RBT::add(Node* tree, int data) {
  bool twored = false;
  if (tree == nullptr) {
    return (new Node(data));
  }
  //if num greater than or equal to tree value
  else if (data >= tree->data) {
    tree->right = add(tree->right, data);
    tree->right->parent = tree;
    if (tree != root) {
      if (strcmp(tree->color, "red") == 0 && strcmp(tree->right->color, "red") == 0) {
	twored = true;
      }
    }
  }
  //num less than tree value
  else {
    tree->left = add(tree->left, data);
    tree->left->parent = tree;
    if (tree != root) {
      if (strcmp(tree->color, "red") == 0 && strcmp(tree->left->color, "red") == 0) {
	twored = true;
      }
    }
  }
  //rotations
  if (right) {
    cout << "right" << endl;
    tree = rightrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->right->color, "red");
    right = false;
  }
  if (left) {
    cout << "left" << endl;
    tree = leftrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->left->color, "red");
    left = false;
  }
  if (rl) {
    cout << "rl" << endl;
    tree->right = rightrotate(tree->right);
    tree->right->parent = tree;
    tree = leftrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->left->color, "red");
    rl = false;
  }
  if (lr) {
    cout << "lr" << endl;
    tree->left = leftrotate(tree->left);
    tree->left->parent = tree;
    tree = rightrotate(tree);
    strcpy(tree->color, "black");
    strcpy(tree->right->color, "red");
    lr = false;
  }
  //2 reds case
  if (twored) {
    cout << "twored" << endl;
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
	if (tree->parent != root) {
	  strcpy(tree->parent->color, "red");
	}
      }
    }
    //if current node is a left child
    else {
      //if sibling is black                                                                               
      if (tree->parent->right == nullptr || strcmp(tree->parent->right->color, "black") == 0) {
        //if left child is red                                                                            
        if (tree->left != nullptr && strcmp(tree->left->color, "red") == 0) {
          right = true;
        }
        //if right child is red                                                                           
        else if (tree->right != nullptr && strcmp(tree->right->color, "red") == 0) {
          lr = true;
        }
      }
      //if sibling is red                                                                                 
      else {
        strcpy(tree->parent->right->color, "black");
        strcpy(tree->color, "black");
        if (tree->parent != root) {
          strcpy(tree->parent->color, "red");
	}
      }
    }
    twored = false;
  }
  return (tree);
}

Node* RBT::leftrotate(Node* node) {
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

Node* RBT::rightrotate(Node* node) {
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
