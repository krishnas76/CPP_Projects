#include <iostream>
#include <cstring>

//#ifndef MEDIA_H
//#define MEDIA_H
#include "Media.h"
//#endif

using namespace std;

Media::Media() {
}

Media::Media(char* newtitle, int newyear) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}
