#include <iostream>
#include <cstring>

#include "Room.h"

using namespace std;

//constructors
Room::Room() {
}

Room::Room(char* newdescription) {
  description = newdescription;
}

void Room::setExit(char* direction, Room* neighbor) {
  exits->insert(pair<char*, Room*>(direction, neighbor));
}

char* Room::getDescription() {
  return description;
}

Room* Room::getExit(char* direction) {
  for 
}

Item* Room::getItem(char* item) {

}
void Room::setItem(Item* item) {

}

void Room::removeItem(char* item) {

}

void Room::getRoomItems() {

}
