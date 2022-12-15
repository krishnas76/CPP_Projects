#include <iostream>
#include <cstring>

#include "Item.h"

using namespace std;

//constructors
Item::Item() {
  description = new char[81];
}

//getters
char* Item::getDescription() {
  return description;
}
