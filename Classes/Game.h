#include <iostream>
#include <cstring>

#include "Media.h"

using namespace std;

class Game : public Media {
 public:

  //contructor
  Game(char*, int, char*, float);

  //functions
  virtual ~Game();
  virtual char* getPublisher();
  virtual int getRating();

  //variables
  char* publisher;
  float rating;
};
