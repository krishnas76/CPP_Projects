#include <iostream>
#include <cstring>

#include "Student.h"

using namespace std;

//constructors
Student::Student() {
  description = new char[81];
}

Student::Student(char* newdescription) {
  description = newdescription;
}
