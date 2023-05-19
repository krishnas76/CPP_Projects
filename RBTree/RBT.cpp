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
  if (twored) {
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

Node* RBT::search(int num) {
  Node* current = root;
  while (current != nullptr) {
    //if number is found
    if (num == current->data) {
      break;
    }
    //if number is less than current's number, go left
    else if (num < current->data) {
      if (current->left == nullptr) {
	break;
      }
      else {
	current = current->left;
      }
    }
    //if number is greater than current's number, go right
    else {
      if (current->right == nullptr) {
	break;
      }
      else {
	current = current->right;
      }
    }
  }
  return current;
}

void RBT::del(Node* node) {
  Node* replace = new Node();
  //node has two children
  if (node->left != nullptr && node->right != nullptr) {
    replace = node->right;
    while (replace->left != nullptr) {
      replace = replace->left;
    }
  }
  //node is leaf
  else if (node->left == nullptr && node->right == nullptr) {
    replace = nullptr;
  }
  //node has right child
  else if (node->right != nullptr) {
    replace = node->right;
  }
  //node has left child
  else {
    replace = node->left;
  }

  //if node is leaf
  if (replace == nullptr) {
    if (node == root) {
      root = nullptr;
    }
    else {
      //two black
      if (strcmp(node->color, "black") == 0) {
	fixtwoblack(node);
      }
      else {
	Node* sibling = new Node();
	if (node->parent->left == node) {
	  sibling = node->parent->right;
	}
	else {
	  sibling = node->parent->left;
	}
	if (sibling != nullptr) {
	  strcpy(sibling->color, "red");
	}
      }
      if (node->parent->left == node)	{
	node->parent->left = nullptr;
      }
      else {
	node->parent->right = nullptr;
      }
    }
    delete node;
  }
  //if node has one child
  else if (node->left == nullptr || node->right == nullptr) {
    if (node == root) {
      node->data = replace->data;
      node->left = nullptr;
      node->right = nullptr;
      delete replace;
    }
    else {
      if (node->parent->left == node)   {
	node->parent->left = replace;
      }
      else {
	node->parent->right = replace;
      }
      replace->parent = node->parent;
      if (strcmp(node->color,"black") == 0 && strcmp(replace->color,"black") == 0) {
	fixtwoblack(replace);
      }
      else {
	strcpy(replace->color, "black");
      }
      delete node;
    }
  }
  //if node has two children
  else {
    int temp = node->data;
    node->data = replace->data;
    replace->data = temp;
    del(replace);
  }
}

void RBT::fixtwoblack(Node* node) {
  //at root, nothing needs to be fixed
  if (node == root) {
    return;
  }
  //set sibling
  Node* sibling = new Node();
  if (node->parent->left == node) {
    sibling = node->parent->right;
  }
  else {
    sibling = node->parent->left;
  }
  //if no sibling
  if (sibling == nullptr) {
    fixtwoblack(node->parent);
  }
  else {
    //if sibling is red
    if (strcmp(sibling->color,"red") == 0) {
      strcpy(node->parent->color,"red");
      strcpy(sibling->color,"black");
      if (sibling->parent->left == sibling) {
	delrightrotate(node->parent);
      }
      else {
	delleftrotate(node->parent);
      }
      fixtwoblack(node);
    }
    //if sibling is black
    else {
      //if sibling has red child
      if ((sibling->left != nullptr && strcmp(sibling->left->color,"red") == 0) ||
	  (sibling->right != nullptr && strcmp(sibling->right->color,"red") == 0)) {
	//sibling's left child is red
	if (sibling->left != nullptr && strcmp(sibling->left->color,"red") == 0) {
	  //sibling is a left child
	  if (sibling->parent->left == sibling) {
	    strcpy(sibling->left->color, sibling->color);
	    strcpy(sibling->color, node->parent->color);
	    delrightrotate(node->parent);
	  }
	  //sibling is a right child
	  else {
	    strcpy(sibling->left->color, node->parent->color);
	    delrightrotate(sibling);
	    delleftrotate(node->parent);
	  }
	}
	//sibling's right child is red
	else {
	  //sibling is a left child
	  if (sibling->parent->left == sibling) {
            strcpy(sibling->right->color, node->parent->color);
            delleftrotate(sibling);
            delrightrotate(node->parent);
          }
          //sibling is a right child 
          else {
            strcpy(sibling->right->color, sibling->color);
            strcpy(sibling->color, node->parent->color);
            delleftrotate(node->parent);
          }
	}
	strcpy(node->parent->color, "black");
      }
      //sibling has no red children
      else {
	strcpy(sibling->color, "red");
	if (strcmp(node->parent->color, "black") == 0) {
	  fixtwoblack(node->parent);
	}
	else {
	  strcpy(node->parent->color, "black");
	}
      }
    }
  }
}

void RBT::delleftrotate(Node* node) {

}

void RBT::delrightrotate(Node* node) {

}
