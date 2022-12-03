#include <iostream>
#include <cstring>

#include "Media.h"

using namespace std;

//constructors
Media::Media() {
}

Media::Media(char* newtitle, int newyear) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
}

//getters
char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
int Media::getType() {
  return type;
}

//destructor
Media::~Media() {
}
