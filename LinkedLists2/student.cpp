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

char* Student::getfname() {
  return fname;
}
char* Student::getlname() {
  return lname;
}
int Student::getid() {
  return id;
}
float Student::getgpa() {
  return gpa;
}
