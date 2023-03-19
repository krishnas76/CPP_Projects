/*This program creates a shunting yard algorithm
 *Author: Krishna Srikanth
 *Date:
 */
#include <iostream>
#include <cstring>
#include <vector>
#include "node.h"
#include "linkedlist.h"

using namespace std;

//function prototypes
int order(char a);
void infix(Node* node);
void prefix(Node* node);
void postfix(Node* node);

int main() {
  //take user input
  cout << "Write a mathematic expression with only single digit numbers and spaces in between each character:" << endl;
  char input[81];
  cin.getline(input, 80, '\n'); //take in user command

  //translate to postfix
  LinkedList* stack = new LinkedList();
  LinkedList* queue = new LinkedList();
  int count = 0;
  for(int i = 0; i < 80; i++) {

    //if character is a number, add to queue
    if (isdigit(input[i])) {
      Node* number = new Node(input[i]);
      queue->enqueue(number);
      count++;
    }

    //if character is an operator
    else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
      Node* operation = new Node(input[i]);
      //while stack isn't empty, top of stack isn't (, top of stack is greater presedence than new operator
      while (stack->peek() != nullptr && stack->peek()->getData() != '(' && order(stack->peek()->getData()) >= order(input[i])) {
	//move operator from top of stack to queue
	queue->enqueue(stack->peek());
	count++;
	stack->pop();
      }
      //push new operator to stack
      stack->push(operation);
    }

    //if character is (, push to stack
    else if (input[i] == '(') {
      Node* operation = new Node(input[i]);
      stack->push(operation);
    }

    //if character is )
    else if (input[i] == ')') {
      Node* operation = new Node(input[i]);
      //while stack isn't empty, top of stack isn't (
      while (stack->peek() != nullptr && stack->peek()->getData() != '(') {
	//move operator from top of stack to queue
	queue->enqueue(stack->peek());
        count++;
        stack->pop();
      }
      //if stask isn't empty, top of stack is (, remove the (
      if (stack->peek() != nullptr && stack->peek()->getData() == '(') {
	stack->pop();
      }
    }
  }

  //transfer remaining operators from stack to queue
  while (stack->peek() != nullptr) {
    if (stack->peek()->getData() != '(') {
      queue->enqueue(stack->peek());
      count++;
      stack->pop();
    }
  }
  
  cout << "Postfix:" << endl;
  
  //translate postfix to expression tree
  LinkedList* treestack = new LinkedList();
  for (int i = 0; i < count; i++) {
    Node* node = queue->dequeue();
    cout << node->data;

    //if its a number, push to stack
    if (isdigit(node->data)) {
      treestack->push(node);
    }

    //if its an operator
    else {
      //move top of stack into right child
      node->right = treestack->peek();
      treestack->pop();
      //move top of stack into left child
      node->left = treestack->peek();
      treestack->pop();
      //push to stack
      treestack->push(node);
    }
  }
  cout << endl;
  Node* tree = treestack->peek();

  //user loop
  while(true) {
    //take user input
    cout << "Type \"infix\", \"prefix\", or \"postfix\" to output the respective notation. Type q to quit." << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command  

    //infix
    if (strcmp(input, "infix") == 0) {
      infix(tree);
      cout << endl;
    }

    //prefix
    else if (strcmp(input, "prefix") == 0) {
      prefix(tree);
      cout << endl;
    }

    //prefix
    else if (strcmp(input, "postfix") == 0) {
      postfix(tree);
      cout << endl;
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

void infix(Node* node) {
  //if tree not empty
  if (node != nullptr) {
    char a = node->data;
    //if operator, print (
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^') {
      cout << "(";
    }
    //infix left child, print data, infix right child
    infix(node->left);
    cout << a;
    infix(node->right);
    //if operator, print )
    if (a == '+' || a == '-' || a == '*' || a == '/' || a == '^') {
      cout << ")";
    }
  }
}

void prefix(Node* node) {
  //if tree not empty
  if (node != nullptr) {
    //print data, prefix left child, prefix right child
    cout << node->data;
    prefix(node->left);
    prefix(node->right);
  }
}

void postfix(Node* node) {
  //if tree not empty
  if (node != nullptr) {
    //postfix left child, postfix right child, print data
    postfix(node->left);
    postfix(node->right);
    cout << node->data;
  }
}

int order(char a) {
  //return presedence of each operator
  if (a == '+' || a == '-') {
    return 1;
  }
  else if (a == '*' || a == '/') {
    return 2;
  }
  else if (a == '^') {
    return 3;
  }
  else if (a == '(') {
    return 4;
  }
  else {
    return 0;
  }
}
