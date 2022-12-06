#include <iostream>
#include <cstring>

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

  
};

#endif
