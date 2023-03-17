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
  cout << input << endl;
  //translate to postfix
  LinkedList* stack = new LinkedList();
  LinkedList* queue = new LinkedList();
  int count = 0;
  for(int i=0; i < 80; i++) {
    if (isdigit(input[i])) {
      Node* number = new Node(input[i]);
      queue->enqueue(number);
      count++;
    }

    else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^') {
      Node* operation = new Node(input[i]);
      while (stack->peek() != nullptr && stack->peek()->getData() != '(' && order(stack->peek()->getData()) >= order(input[i])) {
	queue->enqueue(stack->peek());
	count++;
	stack->pop();
      }
      stack->push(operation);
    }
    else if (input[i] == '(') {
      Node* operation = new Node(input[i]);
      stack->push(operation);
    }
    
    else if (input[i] == ')') {
      Node* operation = new Node(input[i]);
      while (stack->peek() != nullptr && stack->peek()->getData() != '(') {
	queue->enqueue(stack->peek());
        count++;
        stack->pop();
      }
      if (stack->peek() != nullptr && stack->peek()->getData() == '(') {
	stack->pop();
      }
    }
  }
  
  while (stack->peek() != nullptr) {
    if (stack->peek()->getData() != '(') {
      queue->enqueue(stack->peek());
      count++;
      stack->pop();
    }
  }
  
  cout << "done w queue" << endl;

  for (int i = 0; i < count; i++) {
    Node* node = queue->dequeue();
    cout << node->data;
  }
  cout << endl;
  /*
  cout << queue->head->data << queue->head->next->data << queue->head->next->next->data << queue->head->next->next->next->data << endl;
  LinkedList* queue2 = queue;
  while (queue2->dequeue() != nullptr) {
    cout << queue->dequeue()->data;
  }
  */
  /*
  bool removed = true;
  cout << queue->peek()->data << endl;
  while (queue->peek() != nullptr) {
    cout << queue->peek()->data;
    removed = queue->dequeue();
  }
  cout << endl;
  */
  /*
  Node* current = queue->head;
  while (current  != nullptr) {
    cout << current->data;
    current = current->next;
  }
  cout << endl;
  */
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
