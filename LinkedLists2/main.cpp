/*This program creates a student list database using a linked list
 *Author: Krishna Srikanth
 *Date: 
 */


#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>

#include "student.h"
#include "node.h"

using namespace std;

//function prototypes
void addStudent(Node* head);
void addNode(Node* head, Node* node);
void print(Node* head);
void deleteStudent(Node* head);
void average(Node* head);

int main() {
  
  //setting floats to round to two decimals
  cout << fixed;
  cout << setprecision(2);
  
  cout << "This is a Student List." << endl;

  //user command loop
  Student* first = new Student();
  Node* head = new Node(first);
  head->setNext(nullptr);
  while(true) {

    //take user input
    cout << "Type \"ADD\", \"PRINT\", \"DELETE\", \"AVERAGE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      addStudent(head);
    }

    //print
    else if (strcmp(input, "PRINT") == 0) {
      //print();
    }

    //delete
    else if (strcmp(input, "DELETE") == 0) {
      //deleteStudent();
    }

    //average
    else if (strcmp(input, "AVERAGE") == 0) {
      //average();
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

void addStudent(Node* head) {
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
  
  //add student with stored characteristics to linked list
  Student* student = new Student();
  strcpy(student -> fname, fname);
  strcpy(student -> lname, lname);
  student->id = id;
  student->gpa = gpa;
  Node* node = new Node(student);
  node->setNext(nullptr);
  addNode(head, node);

  /*
  if (head == nullptr) {
    head->stuptr = student;
  }
  else if (student->id <= head->stuptr->id) {
    //put new node at start of list
    
  }
  else {
    Node* current = head;
    while (current->next != nullptr) {
      if (student->id >= current->stuptr->id && student->id <= current->next->stuptr->id) {
	//add node after current
	
      }
    }
  }
  */

  cout << "Student added." << endl;
  
}

void addNode(Node* head, Node* node) {
  if (head->getNext() == nullptr) {
    
  }
}

void print(Node* head) {
  /*
  for (int i = 0; i < Studentlist->size(); i++) {
    Student student = *Studentlist->at(i);
    //print out characteristics of each student
    cout << student.fname << " " << student.lname << ", " << student.id << ", " << student.gpa << endl;
  }
  return;
  */
}

void deleteStudent(Node* head) {
  //take in id to delete
  int id;
  cout << "Enter the student ID of the student you wish to delete:  ";
  cin >> id;
  cin.ignore(80, '\n');

  /*
  //remove student from Studentlist
  bool exists = false;
  for (int i = 0; i < Studentlist->size(); i++) {
    if (id == (*Studentlist)[i]->id) {
      exists = true;
      delete *(Studentlist->begin()+i);
      Studentlist->erase(Studentlist->begin()+i);
      break;
    }
  }
  //print if student has been deleted or if student doesn't exist
  if (exists) {
    cout << "Student deleted." << endl;
  }
  else {
    cout << "Student does not exist" << endl;
  }
  */
}

void average(Node* head) {

}
