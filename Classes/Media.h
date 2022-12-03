#include <iostream>
#include <cstring>

//header guard
#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
 public:

  //constructors
  Media();
  Media(char*, int);

  //functions
  virtual ~Media();
  virtual char* getTitle();
  virtual int getYear();
  virtual int getType();

  //variables
  char* title;
  int year;
  int type;
};

#endif
