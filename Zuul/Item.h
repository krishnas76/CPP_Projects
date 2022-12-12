/Users/srikanthsrinivasan/Documents/CPP_Projects/Zuul #include <iostream>
#include <cstring>

//header guard
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
 public:

  //constructors
  Item();
  Item(char*);

  //functions
  virtual char* getDescription();

  //variables
  char* description;

};

#endif
