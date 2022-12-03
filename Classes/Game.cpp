#include <iostream>
#include <cstring>

#include "Game.h"

using namespace std;

//constructor
Game::Game(char* newtitle, int newyear, char* newpublisher, float newrating) {
  title = new char[81];
  strcpy(title, newtitle);
  year = newyear;
  publisher = new char[81];
  strcpy(publisher, newpublisher);
  rating = newrating;
  type = 1;
}

//getters
char* Game::getPublisher() {
  return publisher;
}

int Game::getRating() {
  return rating;
}

//destructors
Game::~Game() {
  delete title;
  delete publisher;
}
