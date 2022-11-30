#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media(char*, int);

  virtual char* getTitle();
  virtual int getYear();
  
 private:
  char* title;
  int year;
};
