#include <iostream>
#include <cstring>

//#ifndef MEDIA_H
//#define MEDIA_H
#include "Media.h"
//#endif

//#ifndef MUSIC_H
//#define MUSIC_H

using namespace std;

class Music : public Media {
 public:
  Music(char*, int, char*, int, char*);

  virtual char* getArtist();
  virtual int getDuration();
  virtual char* getPublisher();

  //private:
  char* artist;
  int duration;
  char* publisher;
};

//#endif
