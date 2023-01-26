#include <iostream>
#include <cstring>

#include "student.h"

using namespace std;

//constructors
Student::Student() {
  fname = new char[81];
  lname = new char[81];
}

Student::Student(char* firstname, char* lastname, int newid, float newgpa) {
  fname = firstname;
  lname = lastname;
  id = newid;
  gpa = newgpa;
}
