/*This program creates a student list database
 *Author: Krishna Srikanth
 *Date: 
 */


#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>

using namespace std;

//creates struct
struct Student {
  char *fname = new char[81];
  char *lname = new char[81];
  int id;
  float gpa;
};

//function prototypes
void addStudent(vector<Student*> *Studentlist);
void print(vector<Student*> *Studentlist);
void deleteStudent(vector<Student*> *Studentlist);

int main() {
  //initializes Studentlist vector
  vector<Student*> *Studentlist = new vector<Student*>();

  //setting floats to round to two decimals
  cout << fixed;
  cout << setprecision(2);
  
  cout << "This is a Student List." << endl;

  //user command loop
  while(true) {

    //take user input
    cout << "Type \"ADD\", \"PRINT\", \"DELETE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      addStudent(Studentlist);
    }

    //print
    else if (strcmp(input, "PRINT") == 0) {
      print(Studentlist);
    }

    //delete
    else if (strcmp(input, "DELETE") == 0) {
      deleteStudent(Studentlist);
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

void addStudent(vector<Student*> *Studentlist) {
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

  //add student with stored characteristics to Studentlist
  Student* student = new Student();
  strcpy(student -> fname, fname);
  strcpy(student -> lname, lname);
  student->id = id;
  student->gpa = gpa;
  Studentlist->push_back(student);
  cout << "Student added." << endl;
}

void print(vector<Student*> *Studentlist) {
  for (int i = 0; i < Studentlist->size(); i++) {
    Student student = *Studentlist->at(i);

    //print out characteristics of each student
    cout << student.fname << " " << student.lname << ", " << student.id << ", " << student.gpa << endl;
  }
  return;
}

void deleteStudent(vector<Student*> *Studentlist) {
  //take in id to delete
  int id;
  cout << "Enter the student ID of the student you wish to delete:  ";
  cin >> id;
  cin.ignore(80, '\n');

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
}
