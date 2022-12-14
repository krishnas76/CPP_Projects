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
  void setExit(char* direction, Room* neighbor);
  char* getDescription();
  Room* getExit(char* direction);
  Item* getItem(char* item);
  vector<Item*> getItems();
  void setItem(Item* item);
  void removeItem(char* item);
  void printRoomItems();

  //variables
  char* description;
  map<char*, Room*> exits;
  vector<Item*> items;
};

#endif
