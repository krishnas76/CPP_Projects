#include <iostream>
#include <cstring>

#include "Media.h"
#include "Music.h"

using namespace std;

//constructor
Music::Music(char* newtitle, int newyear, char* newartist, int newduration, char* newpublisher) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
  artist = new char[81];
  strcpy(artist, newartist);
  duration = newduration;
  publisher = new char[81];
  strcpy(publisher, newpublisher);
  type = 2;
}

//getters
char* Music::getArtist() {
  return artist;
}

int Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}

//destructor
Music::~Music() {
  delete title;
  delete artist;
  delete publisher;
}
