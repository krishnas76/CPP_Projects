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
  Student(char*, char*, int, float);

  //functions
  char* getfname();
  char* getlname();
  int getid();
  float getgpa();
  
  //variables
  char* fname;
  char* lname;
  int id;
  float gpa;

};

#endif
