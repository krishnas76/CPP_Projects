/*This program creates a hash table and a random student generator
 *Author: Krishna Srikanth
 *Date: 
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <fstream>
#include "student.h"
#include "node.h"

using namespace std;

//function prototypes
void addStudent(Node** hashtable, int size);
Student* randStudent();
void print(Node* head);
void deleteStudent(Node* head);
bool deleteNode(Node* head, int id);

int main() {
  
  //setting floats to round to two decimals
  cout << fixed;
  cout << setprecision(2);
  
  cout << "This is a randomly generated student database." << endl;

  int size = 100;
  Node** hashtable = new Node*[100];
  for (int i = 0; i < 100; i++) {
    hashtable[i] = nullptr;
  }
  //hash funtion: gpa * (size/5)
  
  //user command loop
  while(true) {

    //take user input
    cout << "Type \"ADD\", \"GENERATE\", \"PRINT\", \"DELETE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      addStudent(hashtable, size);

    }

    if (strcmp(input, "GENERATE") == 0) {
      addStudent(hashtable, size); 
    }

    //print
    else if (strcmp(input, "PRINT") == 0) {
      //print(head);
    }

    //delete
    else if (strcmp(input, "DELETE") == 0) {
      //deleteStudent(head);
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

Student* randStudent() {
  vector<char*> firstnames [10][20];
  char lastnames [10][20];

  ifstream firstnamefile(firstnames.txt);
  ifstream lastnamefiles(lastnames.txt);

  
  for (int i = 0; i < 10; i++) {
    firstnamefile >> firstnames;
  }


  //add student to linked list
  Node* node = new Node(student);
  node->setNext(nullptr);

  //no collision
  if (hashtable[(int)gpa * (size / 5)] == nullptr) {
    hashtable[(int)gpa*(size/5)] = node;
  }

  //collision
  else {

  }
  cout << "Student added." << endl;
}

void addStudent(Node** hashtable, int size) {
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
  cout << "GPA:  ";
  cin >> gpa;
  cin.ignore(80, '\n');
  
  //make student
  Student* student = new Student();
  strcpy(student->fname, fname);
  strcpy(student->lname, lname);
  student->id = id;
  student->gpa = gpa;

  //add student to linked list
  Node* node = new Node(student);
  node->setNext(nullptr);

  //no collision
  if (hashtable[(int)gpa * (size / 5)] == nullptr) {
    hashtable[(int)gpa*(size/5)] = node;
  }

  //collision
  else {

  }
  cout << "Student added." << endl;
}

void print(Node* head) {
  //if you are not at the end of list
  if (head->getNext() != nullptr) {
    cout << head->getNext()->getStudent()->fname << " " << head->getNext()->getStudent()->lname << ", " << head->getNext()->getStudent()->id << ", " << head->getNext()->getStudent()->gpa << endl;
      print(head->getNext());
  }
}

void deleteStudent(Node* head) {
  //take in id to delete
  int id;
  cout << "Enter the student ID of the student you wish to delete:  ";
  cin >> id;
  cin.ignore(80, '\n');

  //attempt to delete the node
  bool deleted;
  deleted = deleteNode(head, id);

  //if node has been deleted
  if (deleted == true) {
    cout << "Student deleted." << endl;
  }

  //if node doesn't exist
  else {
    cout << "Student does not exist" << endl;
  }
}

bool deleteNode(Node* head, int id) {
  bool deleted;

  //if you are at the end of list
  if (head->getNext() == nullptr) {
    deleted = false;
  }
  
  //if the student's id matches the id to delete
  else if (head->getNext()->getStudent()->id == id) {

    //if it is the last node
    if (head->getNext()->getNext() == nullptr) {
      delete head->getNext();
      head->setNext(nullptr);
    }

    //if the node is in the middle of list
    else {
      Node* temp = head->getNext();
      head->setNext(head->getNext()->getNext());
      delete temp;
    }
    
    deleted = true;
    return deleted;
  }
  
  else {
    deleted = deleteNode(head->getNext(), id);
  }

  return deleted;
}

void average(Node* head, float sum, int count) {
  //if you are not at the end of list
  if (head->getNext() != nullptr) {
    average(head->getNext(), sum + head->getNext()->getStudent()->gpa, count +1);
  }

  //you are at the end of list
  else {
    cout << "Average GPA: " << sum / count << endl;
  }
}
