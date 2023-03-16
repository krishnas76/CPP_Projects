/*This program creates a shunting yard algorithm
 *Author: Krishna Srikanth
 *Date:
 */
#include <iostream>
#include <cstring>
#include <vector>
//#include <bits/stdc++.h>
#include "node.h"
#include "linkedlist.h"

using namespace std;

int order(char a);

int main() {
  //take user input
  cout << "Write a mathematic expression with only single digit numbers and spaces in between each character:" << endl;
  char input[81];
  cin.get(input, 80); //take in user command
  cin.get();
  //translate to postfix
  LinkedList* stack = new LinkedList();
  LinkedList* queue = new LinkedList();
  //int count = sizeof(input)/sizeof(input[0]);
  for(int i=0; i < 80; i++) {
    if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(') {
      Node* operation = new Node(input[i]);
      if (operation->data == ')') {
	while (stack->peek()->data != '(') {
	  queue->enqueue(stack->peek());
	  stack->pop();
	}
	stack->pop();
      }
      else if (order(operation->data)>=order(stack->peek()->data)) {
	cout << "a";
	stack->push(operation);
      }
      else {
	queue->enqueue(stack->peek());
	stack->pop();
      }
    }
    else if (isdigit(input[i])) {
      Node* number = new Node(input[i]);
      queue->enqueue(number);
    }
  }
  char a;
  for (int i =0; i<80; i++) {
    a = queue->dequeue();
    cout << a;
  }
  return 0;
}

int order(char a) {
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
