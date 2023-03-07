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

Node* LinkedList::peak() {
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

bool LinkedList::dequeue() {
  if (head == nullptr) {
    return false;
  }
  if (head == tail) {
    Node* temp = tail;
    tail = nullptr;
    delete temp;
    Node* temp = head;
    head = nullptr;
    delete head;
    return true;
  }
  Node* temp = head;
  head = head->getNext();
  delete temp;
  return true;
}
