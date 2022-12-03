#include <iostream>
#include <cstring>

#include "Media.h"
#include "Movie.h"

using namespace std;

//constructor
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

//getters
char* Movie::getDirector() {
  return director;
}

int Movie::getDuration() {
  return duration;
}

float Movie::getRating() {
  return rating;
}

//destructor
Movie::~Movie() {
  delete title;
  delete director;
}
