#include <iostream>
#include <cstring>

#include "Item.h"

using namespace std;

//constructors
Item::Item() {
}

Item::Item(char* newdescription) {
  description = new char[81];
  strcpy(description, newdescription);
}

//getters
char* Item::getDescription() {
  return description;
}
