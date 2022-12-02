#include <iostream>
#include <cstring>

//#ifndef MEDIA_H
//#define MEDIA_H
#include "Media.h"
//#endif

//#ifndef MOVIE_H
//#define MOVIE_H

using namespace std;

class Movie : public Media {
 public:
  Movie(char*, int, char*, int, float);

  virtual char* getDirector();
  virtual int getDuration();
  virtual float getRating();

  //private:
  char* director;
  int duration;
  float rating;
};

//#endif
