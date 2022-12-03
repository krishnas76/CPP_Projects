#include <iostream>
#include <cstring>

#include "Media.h"

using namespace std;

class Music : public Media {
 public:

  //constructor
  Music(char*, int, char*, int, char*);

  //functions
  virtual ~Music();
  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getPublisher();

  //variables
  char* artist;
  int duration;
  char* publisher;
};
