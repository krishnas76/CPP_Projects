#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media()
  Media(char*, int);

  char* getTitle();
  int getYear();
  
 private:
  char* title;
  int year;
};
