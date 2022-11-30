#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

Media::Media(char* newtitle, int newyear) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
}

virtual char* Media::getTitle() {
  return title;
}

virtual int Media::getYear() {
  return year;
}
