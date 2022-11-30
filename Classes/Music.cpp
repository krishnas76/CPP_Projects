#include <iostream>
#include <cstring>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

#ifndef MUSIC_H
#define MUSIC_H
#include "Music.h"
#endif

using namespace std;

Music::Music(char* newtitle, int newyear, char* newartist, int newduration, char* newpublisher) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
  artist = new char[81];
  strcpy(artist, newartist);
  duration = newduration;
  publisher = new char[81];
  strcpy(publisher, newpublisher);
}

virtual char* Music::getArtist() {
  return artist;
}

virtual int Music::getDuration() {
  return duration;
}

virtual char* Music::getPublisher() {
  return publisher;
}
