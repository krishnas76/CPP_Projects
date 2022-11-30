#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

class Game : public Media {
 public:
  Game(char*, int, char*, float);

  virtual char* getPublisher();
  virtual int getRating();

 private:
  char* publisher;
  float rating;
};

