/*This program creates a digital media database
 *Author: Krishna Srikanth
 *Date:
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>

//#ifndef MEDIA_H
//#define MEDIA_H
#include "Media.h"
//#endif

//#ifndef GAME_H
//#define GAME_H
#include "Game.h"
//#endif

//#ifndef MUSIC_H
//#define MUSIC_H
#include "Music.h"
//#endif

//#ifndef MOVIE_H
//#define MOVIE_H
#include "Movie.h"
//#endif

using namespace std;

int main() {
  //initializes Studentlist vector
  vector<Media*> *Database = new vector<Media*>();

  //test
  //char* title_test = new char[81];
  //strcpy(title_test, "Black Panther");
  //int year_test = 2005;
  //Media* test = new Media(title_test, year_test);
  //cout << test->getTitle() << endl;
  
  cout << "This is Media Database." << endl;

  //user command loop
  while(true) {

    //take user input
    cout << "Type \"ADD\", \"SEARCH\", \"DELETE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      cout << "Which type of Media would you like to add? Type \"VIDEOGAME\", \"MUSIC\", or \"MOVIE\"" << endl;
      char type[81];
      cin.getline(type, 80, '\n'); //take in user command
      if (strcmp(type, "VIDEOGAME") == 0) {
	
      }
      else if (strcmp(type, "MUSIC") == 0) {

      }
      else if (strcmp(type, "MOVIE") == 0) {

      }
      else {
	cout << "Invalid input." << endl;
      }
    }

    //print
    else if (strcmp(input, "SEARCH") == 0) {
      cout << "
    }

    //delete
    else if (strcmp(input, "DELETE") == 0) {
      
    }

    //quit
    else if (strcmp(input, "QUIT") == 0) {
      break;
    }

    //invalid input
    else {
      cout << "That is not a valid command." << endl;
    }


  }

  return 0;
}
