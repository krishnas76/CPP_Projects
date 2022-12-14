/*This program creates Zuul, an adventure game
 *Author: Krishna Srikanth
 *Date:
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>

#include "Item.h"
#include "Room.h"
using namespace std;

void printHelp();

int main() {

  //intro message
  cout << "Welcome to Krishna's Kingly Key!" << endl;
  cout << "The goal of this game is to find the Krishna's Kingly Key and use it to open the vault." << endl;
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
  char abook[5] = "book";
  Item* book = new Item(abook);
  char apenny[6] = "penny";
  Item* penny = new Item(apenny);
  char amilk[5] = "milk";
  Item* milk = new Item(amilk);
  char abandaid[8] = "bandaid";
  Item* bandaid = new Item(abandaid);
  char akey[4] = "key";
  Item* key = new Item(akey);
  char aburger[7] = "burger";
  Item* burger = new Item(aburger);
  char afries[6] = "fries";
  Item* fries = new Item(afries);
  char apancake[8] = "pancake";
  Item* pancake = new Item(apancake);

  //setting items in rooms
  library->setItem(book);
  bank->setItem(penny);
  farm->setItem(milk);
  hospital->setItem(bandaid);
  gas->setItem(key);
  mcdonalds->setItem(burger);
  mcdonalds->setItem(fries);
  ihop->setItem(pancake);
  
  vector<Item*> *inventory = new vector<Item*>();
  
  //game loop
  while (true) {
    char input[81];
    cin >> input;
    cin.get();

    if (strcmp(input, "help") == 0) {
      printHelp();
    }
    
    else if (strcmp(input, "go") == 0) {
      cout << "What direction would you like to go? (north/east/south/west)" <<  endl;
      char direction[81];
      cin >> direction;
      cin.get();
      Room* nextRoom = currentRoom->getExit(direction);
      if (nextRoom == NULL) {
	cout << "There is nothing there!" << endl;
      }
      else {
	currentRoom = nextRoom;
	cout << currentRoom->getDescription() << endl;
	cout << "Items available:" << endl;
	currentRoom->printRoomItems();
	//win condition
      }
    }
    
    else if (strcmp(input, "get") == 0) {
      
    }
    
    else if (strcmp(input, "drop") == 0) {
     
    }
    
    else if (strcmp(input, "inventory") == 0) {
      if (inventory->size() == 0) {
      	cout << "Your inventory is empty." << endl;
      }
      else {
	vector<Item*>::iterator it;
	for (it = inventory->begin(); it < inventory->end(); it++) {
	  cout << (*it)->getDescription() << " ";
	}
	cout << endl;
      }
    }
    
    else if (strcmp(input, "quit") == 0) {
      cout << "Bye!" << endl;
      break;
    }

    else {
      cout << "That is not a valid command word." << endl;
    }


 
    //for (int i = 0; i < strlen(input); i++) {
    //if (input[i] != 32) {
    //	if (words == 0) {
    //	  word1[i] = input[i];
    //	}
    //	else if (words == 1) {
    //	  word1[i] = '\0';
    //	  word2[i-strlen(word1) - 2] = input[i];
    //	}
    //}
    //else if (input[i] == '\0') {
    //	break;
    //}
    //else {
    //	words++;
    //}
    // }
    
  }


  return 0;
}

void printHelp() {
  cout << "Enter a command word. Your command words are:" << endl;
  cout << "help, go, get, drop, inventory, quit" << endl;
}
