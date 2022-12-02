#include <iostream>
#include <cstring>
#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
 public:
  Media();
  Media(char*, int);
  virtual char* getTitle();
  virtual int getYear();
  
  // private:
  char* title;
  int year;
};

#endif
