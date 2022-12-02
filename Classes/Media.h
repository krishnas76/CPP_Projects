#include <iostream>
#include <cstring>
#ifndef MEDIA_H
#define MEDIA_H

using namespace std;

class Media {
 public:
  Media();
  virtual ~Media();
  Media(char*, int);
  virtual char* getTitle();
  virtual int getYear();
  virtual int getType();
  
  // private:
  char* title;
  int year;
  int type;
};

#endif
