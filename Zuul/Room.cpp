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

//functions
void Room::setExit(char* direction, Room* neighbor) {
  exits.insert(make_pair(direction, neighbor));
}

char* Room::getDescription() {
  return description;
}

Room* Room::getExit(char* direction) {
  map<char*, Room*>::iterator it;
  for (it = exits.begin(); it != exits.end(); ++it) {
    if (strcmp(it->first, direction) == 0) {
      return it->second;
    }
  }
  return NULL;
}

Item* Room::getItem(char* item) {
  vector<Item*>::iterator it;
  for (it = items.begin(); it < items.end(); it++) {
    if (strcmp((*it)->getDescription(), item) == 0) {
      return *it;
    }
  }
  return NULL;
}

vector<Item*> Room::getItems() {
  return items;
}

void Room::setItem(Item* item) {
  items.push_back(item);
}

void Room::removeItem(char* item) {
  vector<Item*>::iterator it;
  int index = 0;
  for (it = items.begin(); it < items.end(); it++) {
    if (strcmp((*it)->getDescription(), item) == 0) {
      items.erase(items.begin()+index);
      break;
    }
  }
  index++;
}

void Room::printRoomItems() {
  if (items.size() == 0) {
    cout << "None." << endl;
  }
  vector<Item*>::iterator it;
  for (it = items.begin(); it < items.end(); it++) {
    cout << (*it)->getDescription() << endl;
  }
}
