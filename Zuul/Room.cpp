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
  map<char*, Room*>::iterator it;
  for (it = exits->begin(); it != exits->end(); ++it) {
    if (it->first == direction) {
      return it->second;
    }
  }
  return NULL;
}

Item* Room::getItem(char* item) {
  vector<Item*>::iterator it;
  for (it = items->begin(); it < items->end(); it++) {
    if ((*it)->getDescription() == item) {
      return *it;
    }
  }
  return NULL;
}
void Room::setItem(Item* item) {
  items->push_back(item);
}

void Room::removeItem(char* item) {
  vector<Item*>::iterator it;
  int index =	0;
  for (it = items->begin(); it < items->end(); it++) {
    if ((*it)->getDescription() == item) {
      //delete item
      delete *it;
      items->erase(items->begin()+index);
      break;
    }
  }
  index++;
}

void Room::printRoomItems() {
  vector<Item*>::iterator it;
  for (it = items->begin(); it < items->end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
}
