#include <iostream>
#include <cstring>
#include <map>
#include <vector>

#include "Item.h"

//header guard
#ifndef ROOM_H
#define ROOM_H

using namespace std;

class Room {
 public:

  //constructors
  Room();
  Room(char*);

  //functions
  virtual void setExit(char* direction, Room* neighbor);
  virtual char* getDescription();
  virtual Room* getExit(char* direction);
  virtual Item* getItem(char* item);
  virtual void setItem(Item item);
  virtual void removeItem(char* item);
  virtual void getRoomItems();

  //variables
  char* description;
  map<5, 4> exits;
  vector<Item*> *items = new vector<Item*>();
};

#endif
B
