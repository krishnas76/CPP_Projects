#include <iostream>
#include <cstring>

//header guard
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:

  //constructors
  Student();
  Student(char*);

  //functions
  //char* getDescription();

  //variables
  char* description;

};

#endif
