#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

//constructor
LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

void LinkedList::push(Node* node) {
  if (head == nullptr) {
    head = node;
  }
  else {
    node->setNext(head);
    head = node;
  }
}

bool LinkedList::pop() {
  if (head == nullptr) {
    return false;
  }
  Node* temp = head;
  head = head->getNext();
  delete temp;
  return true;
}

Node* LinkedList::peek() {
  return head;
}

void LinkedList::enqueue(Node* node) {
  if (head == nullptr) {
    head = node;
    tail = node;
  }
  else {
    tail->setNext(node);
    tail = node;
  }
}

char LinkedList::dequeue() {
  if (head == nullptr) {
    return '\0';
  }
  if (head == tail) {
    char data = head->data;
    Node* temp = tail;
    tail = nullptr;
    delete temp;
    Node* temp2 = head;
    head = nullptr;
    delete temp2;
    return data;
  }
  char data = head->data;
  Node* temp = head;
  head = head->getNext();
  delete temp;
  return data;
}
