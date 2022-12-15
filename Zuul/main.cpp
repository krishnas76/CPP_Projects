/*This program creates Zuul, an adventure game
 *Author: Krishna Srikanth
 *Date: 12/14/2022
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "Item.h"
#include "Room.h"
using namespace std;

//declaring functions
void printHelp();

int main() {

  //intro message
  cout << "Welcome to Krishna's Key!" << endl;
  cout << "The goal of this game is to find Krishna's Key and use it to open the vault." << endl;
  cout << "Type \"help\" if you need help." << endl;

  //initializing rooms
  char Street[100] = "You are in the center of a city. Don't get lost! Exits: north, south, east, west";
  Room* street = new Room(Street);
  char Townhall[80] = "You are in the city townhall. Exits: north, south";
  Room* townhall = new Room(Townhall);
  char Mayor[80] = "You are in the mayor's office. Exits: south";
  Room* mayor = new Room(Mayor);
  char Police[80] = "You are in a police station. Exits: east, west";
  Room* police = new Room(Police);
  char Fire[80] = "You are in a fire station. Exits, north, east, south";
  Room* fire = new Room(Fire);
  char Library[80] = "You are in a library. There's a bunch of books here. Exits: east, south";
  Room* library = new Room(Library);
  char Bank[80] = "You are in the city bank. Seems very secure... Exits: north, west";
  Room* bank = new Room(Bank);
  char Farm[80] = "You are in a vast farm. You hear a cow go moo. Exits: north";
  Room* farm = new Room(Farm);
  char Hilton[80] = "You are in a Hilton Hotel. Exits: north, south, west";
  Room* hilton = new Room(Hilton);
  char Ihop[80] = "You are in an IHOP restaurant. Pancakes here are delicious! Exits: north";
  Room* ihop = new Room(Ihop);
  char Gas[100] = "You are in a gas station. Hmm, there's something shiny on the ground... Exits: north, east";
  Room* gas = new Room(Gas);
  char Skyscraper[80] = "You are in a super tall skyscraper. Exits: north, west";
  Room* skyscraper = new Room(Skyscraper);
  char Mcdonalds[100] = "You are in a McDonalds. There's a sale for burgers and fries! Exits: north, south, west";
  Room* mcdonalds = new Room(Mcdonalds);
  char Mall[80] = "You are in a giant mall. So many escalators. Exits: south";
  Room* mall = new Room(Mall);
  char Panda[80] = "You are in a Panda Express. Sadly, there's no food here. Exits: north, south";
  Room* panda = new Room(Panda);
  char Hospital[80] = "You are in a hospital. Exits: east, south";
  Room* hospital = new Room(Hospital);
  char Vault[80] = "You are in the bank vault. You need a key to open it... Exits: south";
  Room* vault = new Room(Vault);

  //setting exits
  char north[80] = "north";
  char south[80] = "south";
  char east[80] = "east";
  char west[80] = "west";
  street->setExit(north, townhall);
  street->setExit(east, mcdonalds);
  street->setExit(south, hilton);
  street->setExit(west, police);
  
  townhall->setExit(south, street);
  townhall->setExit(north, mayor);
  
  mayor->setExit(south, townhall);
  
  police->setExit(east, street);
  police->setExit(west, fire);
  
  fire->setExit(east, police);
  fire->setExit(north, library);
  fire->setExit(south, farm);
  
  library->setExit(south, fire);
  library->setExit(east, bank);
  
  bank->setExit(west, library);
  bank->setExit(north, vault);
  
  vault->setExit(south, bank);
  
  farm->setExit(north, fire);
  
  hilton->setExit(north, street);
  hilton->setExit(west, hospital);
  hilton->setExit(south, skyscraper);
  
  hospital->setExit(east, hilton);
  hospital->setExit(south, gas);

  gas->setExit(north, hospital);
  gas->setExit(east, skyscraper);
  
  skyscraper->setExit(north, hilton);
  skyscraper->setExit(west, gas);
  
  mcdonalds->setExit(west, street);
  mcdonalds->setExit(north, mall);
  mcdonalds->setExit(south, panda);
  
  mall->setExit(south, mcdonalds);
  
  panda->setExit(north, mcdonalds);
  panda->setExit(south, ihop);
  
  ihop->setExit(north, panda);

  //starting room
  Room* currentRoom = street;
  cout << currentRoom->getDescription() << endl;
  cout << "Items available:" << endl;
  currentRoom->printRoomItems();

  //initializing items
  char abook[] = "book";
  Item* book = new Item();
  strcpy(book->description, abook);
  char apenny[] = "penny";
  Item* penny = new Item();
  strcpy(penny->description, apenny);
  char amilk[] = "milk";
  Item* milk = new Item();
  strcpy(milk->description, amilk);
  char abandaid[] = "bandaid";
  Item* bandaid = new Item();
  strcpy(bandaid->description, abandaid);
  char akey[] = "key";
  Item* key = new Item();
  strcpy(key->description, akey);
  char aburger[] = "burger";
  Item* burger = new Item();
  strcpy(burger->description, aburger);
  char afries[] = "fries";
  Item* fries = new Item();
  strcpy(fries->description, afries);
  char apancake[] = "pancake";
  Item* pancake = new Item();
  strcpy(pancake->description, apancake);

  //setting items in rooms
  library->setItem(book);
  bank->setItem(penny);
  farm->setItem(milk);
  hospital->setItem(bandaid);
  gas->setItem(key);
  mcdonalds->setItem(burger);
  mcdonalds->setItem(fries);
  ihop->setItem(pancake);

  //creating inventory
  vector<Item*> *inventory = new vector<Item*>();

  //creating full list of items
  vector<Item*> *itemList = new vector<Item*>();
  itemList->push_back(book);
  itemList->push_back(penny);
  itemList->push_back(milk);
  itemList->push_back(bandaid);
  itemList->push_back(key);
  itemList->push_back(burger);
  itemList->push_back(fries);
  itemList->push_back(pancake);
  
  //game loop
  while (true) {
    char input[81];
    cin >> input;
    cin.get();

    //help
    if (strcmp(input, "help") == 0) {
      printHelp();
    }

    //go
    else if (strcmp(input, "go") == 0) {
      //take in direction
      cout << "What direction would you like to go? (north/east/south/west)" <<  endl;
      char direction[81];
      cin >> direction;
      cin.get();
      Room* nextRoom = currentRoom->getExit(direction); //see if there is a room in that direction
      if (nextRoom == NULL) { //no room in that direction
	cout << "There is nothing there!" << endl;
      }
      else { //room in that direction exists
	//move to new room
	currentRoom = nextRoom;
	cout << currentRoom->getDescription() << endl;
	cout << "Items available:" << endl;
	currentRoom->printRoomItems();

	//win condition
	if (currentRoom == vault && find(inventory->begin(), inventory->end(), key) != inventory->end()) {
	  cout << "You win!" << endl;
	  break;
	}
      }
    }

    //get
    else if (strcmp(input, "get") == 0) {
      if (currentRoom->getItems().size() == 0) { //if no items in room
	cout << "There are no items here." << endl;
      }
      else { //if there are items in room
	cout << "Which item would you like to get?" << endl;
	char pickitem[80];
	cin >> pickitem;
	cin.get();
	if (currentRoom->getItem(pickitem) != NULL) { //if specified item is in room, pick it up
	  inventory->push_back(currentRoom->getItem(pickitem));
	  currentRoom->removeItem(pickitem);
	  cout << "Picked up " << pickitem << "!" << endl;
	}
	else { //specified item not in room
	  cout << "That item is not here!" << endl;
	}
      }
    }

    //drop
    else if (strcmp(input, "drop") == 0) {
      if (inventory->size() == 0) { //if nothing in inventory
        cout << "You have no items to drop." << endl;
      }
      else { //inventory has items in it
	cout << "Which item would you like to drop?" << endl;
        char dropitem[80];
        cin >> dropitem;
        cin.get();
	vector<Item*>::iterator it;
	bool exists = false;
        for (it = itemList->begin(); it < itemList->end(); it++) {
	  if (strcmp((*it)->getDescription(), dropitem) == 0) { //if item exists, find item in inventory
	    exists = true;
	    vector<Item*>::iterator itr;
	    int index = 0;
	    bool found = false;
	    for (itr = inventory->begin(); itr < inventory->end(); itr++) {
	      if (strcmp((*itr)->getDescription(), dropitem) == 0) { //if item is in inventory, drop it
		currentRoom->setItem(*itr);
		inventory->erase(inventory->begin()+index);
		cout << "Item dropped." << endl;
		found = true;
	      }
	    }
	    if (found == false) {
	      cout << "You do not have this item." << endl;
	    }	
	  }
	}
	if (exists == false) {
	  cout << "That item does not exist."	<< endl;
	}
      }
    }

    //inventory
    else if (strcmp(input, "inventory") == 0) {
      if (inventory->size() == 0) {
      	cout << "Your inventory is empty." << endl;
      }
      else { //if inventory isn't empty, print items in inventory
	vector<Item*>::iterator it;
	cout << "You have:" << endl;
	for (it = inventory->begin(); it < inventory->end(); it++) {
	  cout << (*it)->getDescription() << endl;
	}
      }
    }

    //quit
    else if (strcmp(input, "quit") == 0) {
      cout << "Bye!" << endl;
      break;
    }

    else {
      cout << "That is not a valid command word." << endl;
    }
  }


  return 0;
}

void printHelp() {
  cout << "Enter a command word. Your command words are:" << endl;
  cout << "help, go, get, drop, inventory, quit" << endl;
}
