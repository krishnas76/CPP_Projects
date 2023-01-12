#include <iostream>
#include <cstring>

#include "student.h"

using namespace std;

//constructors
Student::Student() {
  
}

Student::Student(char* firstname, char* lastname, int newid, float newgpa) {
  fname = firstname;
  lname = lastname;
  id = newid;
  gpa = newgpa;
}
