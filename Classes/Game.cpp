#include <iostream>
#include <cstring>

//#ifndef MEDIA_H
//#define MEDIA_H
//#include "Media.h"
//#endif

//#ifndef GAME_H
//#define GAME_H
#include "Game.h"
//#endif

using namespace std;

Game::Game(char* newtitle, int newyear, char* newpublisher, float newrating) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
  publisher = new char[81];
  strcpy(publisher, newpublisher);
  rating = newrating;
}

char* Game::getPublisher() {
  return publisher;
}

int Game::getRating() {
  return rating;
}
