#include <iostream>
#include <cstring>

#include "Media.h"

using namespace std;

class Movie : public Media {
 public:

  //constructor
  Movie(char*, int, char*, int, float);

  //functions
  virtual ~Movie();
  virtual char* getDirector();
  virtual int getDuration();
  virtual float getRating();

  //variables
  char* director;
  int duration;
  float rating;
};
