#include <iostream>
#include <cstring>

//#ifndef MEDIA_H
//#define MEDIA_H
#include "Media.h"
//#endif

//#ifndef MOVIE_H
//#define MOVIE_H
#include "Movie.h"
//#endif

using namespace std;

Movie::Movie(char* newtitle, int newyear, char* newdirector, int newduration, float newrating) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
  director = new char[81];
  strcpy(director, newdirector);
  duration = newduration;
  rating = newrating;
  type = 3;
}

char* Movie::getDirector() {
  return director;
}

int Movie::getDuration() {
  return duration;
}

float Movie::getRating() {
  return rating;
}
