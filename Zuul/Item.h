#include <iostream>
#include <cstring>

//header guard
#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
 public:

  //constructors
  Item();
  //Item(char*);

  //functions
  char* getDescription();

  //variables
  char* description;

};

#endif