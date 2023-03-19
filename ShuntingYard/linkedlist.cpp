#include <bits/stdc++.h>
#include "linkedlist.h"

using namespace std;

//constructor
LinkedList::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

void LinkedList::push(Node* node) {
  //if head is null, set head to node
  if (head == nullptr) {
    head = node;
  }
  //else, set the node as the new head
  else {
    node->setNext(head);
    head = node;
  }
}

bool LinkedList::pop() {
  //if stack is empty, return false
  if (head == nullptr) {
    return false;
  }
  //if not, set head as next
  head = head->getNext();
  return true;
}

Node* LinkedList::peek() {
  return head;
}

void LinkedList::enqueue(Node* node) {
  //if queue empty, set head and tail to be node
  if (head == nullptr) {
    head = node;
    tail = node;
  }
  //if not, add node to end of queue
  else {
    tail->setNext(node);
    tail = node;
  }
}

Node* LinkedList::dequeue() {
  //if queue empty, return nullptr
  if (head == nullptr) {
    return nullptr;
  }
  //if queue has one element, remove that element and return it
  if (head == tail) {
    Node* node = head;
    tail = nullptr;
    head = nullptr;
    return node;
  }
  //if queue has more than one element, remove first element and return it
  Node* node = head;
  head = head->getNext();
  return node;
}
