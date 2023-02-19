/*This program creates a hash table and a random student generator
 *Author: Krishna Srikanth
 *Date: 2/18/23
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <cmath>
#include "student.h"
#include "node.h"

using namespace std;

//function prototypes
int addHash(Node** hashtable, int size, Student* student);
int rehash(int size, Node** hashtable, Student* student);
void rehashloop(Node** hashtable, Node* node, int size);
int randStudent(int count, Node** hashtable, int size);
void print(Node** hashtable, int size);
void printloop(Node* node);
void deleteStudent(Node** hashtable, int size);
bool deleteNode(Node** hashtable, int id, Node* node, int index);

int main() {
  
  //setting floats to round to two decimals
  cout << fixed;
  cout << setprecision(2);
  
  cout << "This is a randomly generated student database." << endl;

  //initializing size and hashtable
  int size = 100;
  Node** hashtable = new Node*[100];
  for (int i = 0; i < size; i++) {
    hashtable[i] = nullptr;
  }
  
  //user command loop
  while(true) {
 
    //take user input
    cout << "Type \"ADD\", \"GENERATE\", \"PRINT\", \"DELETE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      //take in student characteristics
      char fname[81];
      char lname[81];
      int id;
      float gpa;
      cout << "First name:  ";
      cin >> fname;
      cout << "Last name:  ";
      cin >> lname;
      cout << "Student ID:  ";
      cin >> id;
      cout << "GPA (0-5):  ";
      cin >> gpa;
      cin.ignore(80, '\n');
      
      //make student
      Student* student = new Student();
      strcpy(student->fname, fname);
      strcpy(student->lname, lname);
      student->id = id;
      student->gpa = gpa;

      size = addHash(hashtable, size, student);

      cout << "Student added." << endl;      
    }

    //generate
    if (strcmp(input, "GENERATE") == 0) {
      int count = 0;
      cout << "How many students do you want to generate?" << endl;
      cin >> count;
      cin.ignore(80, '\n');
      size = randStudent(count, hashtable, size); 
    }

    //print
    else if (strcmp(input, "PRINT") == 0) {
      print(hashtable, size);
    }

    //delete
    else if (strcmp(input, "DELETE") == 0) {
      deleteStudent(hashtable, size);
    }

    //quit
    else if (strcmp(input, "QUIT") == 0) {
      break;
    }

    //invalid input
    else {
      cout << "That is not a valid command." << endl;
    }
  }

  return 0;
}

int addHash(Node** hashtable, int size, Student* student) {
  int index = student->id % size;

  Node* node = new Node(student);
  node->setNext(nullptr);

  //no collision
  if (hashtable[index] == nullptr) {
    hashtable[index] = node;
  }
  
  //collisions
  else if (hashtable[index]->getNext() == nullptr) {
    hashtable[index]->setNext(node);
  }
  
  else if (hashtable[index]->getNext()->getNext() == nullptr) {
    hashtable[index]->getNext()->setNext(node);
  }

  else {
    size = rehash(size * 2, hashtable, student);
  }

  return size;
  
}

int rehash(int size, Node** hashtable, Student* student) {
  //make newhashtable
  Node** newhashtable = new Node*[size];
  for (int i = 0; i < size; i++) {
    newhashtable[i] = nullptr;
  }

  //transfer all old entries to newhashtable
  addHash(newhashtable, size, student);
  for (int i = 0; i < size / 2; i++) {
    rehashloop(newhashtable, hashtable[i], size);
  }

  hashtable = newhashtable;
  return size;

}

void rehashloop(Node** hashtable, Node* node, int size) {
  //if node isn't null, add it to the hashtable and move on to the next node
  if (node != nullptr) {
    addHash(hashtable, size, node->getStudent());
    rehashloop(hashtable, node->getNext(), size);
  }
}


int randStudent(int count, Node** hashtable, int size) {
  int newsize = size;
  srand (time(NULL));
  for (int i = 0; i < count; i++) {

    //get first name
    ifstream firstname ("firstnames.txt");
    char first[81];
    char temp[81];
    for (int j = 0; j < ((rand()%10)+1); j++) {
      firstname >> temp;
    }
    firstname >> first;
    
    //get last name
    ifstream lastname ("lastnames.txt");
    char last[81];
    for (int j = 0; j < (rand()%10+1); j++) {
      lastname >> temp;
    }
    lastname >> last;

    //make id and gpa
    int id = 300000 + i;
    float gpa = (float)(rand() % 500 + 1) / 100;

    //make student
    Student* student = new Student();
    strcpy(student->fname, first);
    strcpy(student->lname, last);
    student->id = id;
    student->gpa = gpa;

    //add student to hashtable
    newsize = addHash(hashtable, size, student);
    cout << "Student generated: " << first << " " << last << ", " << id << ", " << gpa << endl;
    
  }

  return newsize;
  
}
  

void print(Node** hashtable, int size) {
  //iterate through hashtable
  for (int i = 0; i < size; i++) {
    printloop(hashtable[i]);
  }
}

void printloop(Node* node) {
  //if node isn't null, print the student then move on to the next node
  if (node != nullptr) {
    Student* student = node->getStudent();
    cout << student->fname << " " << node->getStudent()->lname << ", " << node->getStudent()->id << ", " << node->getStudent()->gpa << endl;
    printloop(node->getNext());
  }
}

void deleteStudent(Node** hashtable, int size) {
  //take in id to delete
  int id;
  cout << "Enter the student ID of the student you wish to delete:  ";
  cin >> id;
  cin.ignore(80, '\n');

  int index = id % size;
  
  //if node has been deleted
  if (deleteNode(hashtable, id, hashtable[index], index)) {
    cout << "Student deleted." << endl;
  }

  //if node doesn't exist
  else {
    cout << "Student does not exist." << endl;
  }               
}

bool deleteNode(Node** hashtable, int id, Node* node, int index) {
  bool deleted = false;

  //if node is empty
  if (node == nullptr) {
    deleted = false;
    return deleted;
  }
  
  //if the first student's id matches the id to delete
  if (node->getStudent()->id == id) {
    //if it is the only node
    if (node == hashtable[index] && node->getNext() == nullptr) {
      delete node;
      hashtable[index] = nullptr;
    }

    //if there are nodes after it
    else {
      hashtable[index] = node->getNext();
      delete node;
    }
    
    deleted = true;
    return deleted;
  }

  //if the next student matches the id to delete
  else if (node->getNext()->getStudent()->id == id) {
    //if it is the last node
    if (node->getNext()->getNext() == nullptr) {
      delete node->getNext();
      node->setNext(nullptr);
    }

    //if there are nodes after it
    else {
      Node* temp = node->getNext();
      node->setNext(node->getNext()->getNext());
      delete temp;
    }

    deleted = true;
    return deleted;
  }

  else {
    deleted = deleteNode(hashtable, id, node->getNext(), index);
  }
  
  return deleted;
}
