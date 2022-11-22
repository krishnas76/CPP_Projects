#include <iostream>

using namespace std;

class Media {
 public:
  Media(char* title[81], int year);

  char getTitle();
  
 protected:
  char* title = new char[81];
  int year;
}
