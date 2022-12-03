/*This program creates a digital media database
 *Author: Krishna Srikanth
 *Date: 12/2/22
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>

#include "Media.h"
#include "Game.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void search(vector<Media*> *Database);
void deleteMedia(vector<Media*> *Database);

int main() {
  //initializes Studentlist vector
  vector<Media*> *Database = new vector<Media*>();

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

      if (strcmp(type, "VIDEOGAME") == 0) { //Video game
	//add a video game

	//take in input
	char title[81];
	int year;
	char publisher[81];
	float rating;
	cout << "Title:  ";
	cin.get(title, 80);
	cin.get();
	cout << "Year:  ";
	cin >> year;
	cin.get();
	cout << "Publisher:  ";
	cin.get(publisher, 80);
	cin.get();
	cout << "Rating:  ";
	cin >> rating;
	cin.get();

	//add game to Database
	Game* game = new Game(title, year, publisher, rating);
	Database->push_back(game);
	cout << "Game added to database." << endl;
      }
      else if (strcmp(type, "MUSIC") == 0) { //Music
	//add music

	//take in input
        char title[81];
        int year;
        char artist[81];
        int duration;
	char publisher[81];
        cout << "Title:  ";
        cin.get(title, 80);
        cin.get();
        cout << "Year:  ";
        cin >> year;
        cin.get();
	cout << "Artist:  ";
        cin.get(artist, 80);
        cin.get();
	cout << "Duration (minutes):  ";
        cin >> duration;
        cin.get();
        cout << "Publisher:  ";
        cin.get(publisher, 80);
        cin.get();

	//add music to Database
        Music* music = new Music(title, year, artist, duration, publisher);
        Database->push_back(music);
        cout << "Music added to database." << endl;

      }
      else if (strcmp(type, "MOVIE") == 0) { //Movie
	//add movie

	//take in input
        char title[81];
        int year;
        char director[81];
        int duration;
        float rating;
        cout << "Title:  ";
        cin.get(title, 80);
        cin.get();
        cout << "Year:  ";
        cin >> year;
        cin.get();
        cout << "Director:  ";
        cin.get(director, 80);
        cin.get();
        cout << "Duration (minutes):  ";
        cin >> duration;
        cin.get();
        cout << "Rating:  ";
        cin >> rating;
        cin.get();

	//add movie to Database
        Movie* movie = new Movie(title, year, director, duration, rating);
        Database->push_back(movie);
        cout << "Movie added to database." << endl;

      }
      else { //input is invalid
	cout << "Invalid input." << endl;
      }
    }

    //search
    else if (strcmp(input, "SEARCH") == 0) {
      search(Database);
    }
    
    //delete
    else if (strcmp(input, "DELETE") == 0) {
      deleteMedia(Database);
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

void search(vector<Media*> *Database) {

  //take user input
  cout << "Would you like to search by title or year? Type \"TITLE\" or \"YEAR\"" << endl;
  char search[81];
  cin.getline(search, 80, '\n'); //take in user command

  //search by title
  if (strcmp(search, "TITLE") == 0) {
    //take user input
    char title[81];
    cout << "Enter the title you want to search for: " << endl;
    cin.getline(title, 80, '\n'); //take in user command
    bool found = false;
    for (int i = 0; i < Database->size(); i++) {
      if (strcmp(Database->at(i)->getTitle(), title) == 0) {
	if (Database->at(i)->getType() == 1) { //video game
	  Game* game = static_cast<Game*>(Database->at(i)); //cast to Game
	  cout << "Media found!" << endl;
	  cout << "Type: Video game" << endl;
	  cout << "Title: " << game->getTitle() << endl;
	  cout << "Year: " << game->getYear() << endl;
	  cout << "Publisher: " << game->getPublisher() << endl;
	  cout << "Rating: " << game->getRating() << endl;
	}
	if (Database->at(i)->getType() == 2) { //music
	  Music* music = static_cast<Music*>(Database->at(i)); //cast to Music
	  cout << "Media found!" << endl;
	  cout << "Type: Music" << endl;
	  cout << "Title: " << music->getTitle() << endl;
	  cout << "Year: " << music->getYear() << endl;
	  cout << "Artist: " << music->getArtist() << endl;
	  cout << "Duration: " << music->getDuration() << endl;
	  cout << "Publisher: " << music->getPublisher() << endl;
	}
	if (Database->at(i)->getType() == 3) { //movie
	  Movie* movie = static_cast<Movie*>(Database->at(i)); //cast to Movie
	  cout << "Media found!" << endl;
	  cout << "Type: Movie" << endl;
	  cout << "Title: " << movie->getTitle() << endl;
	  cout << "Year: " << movie->getYear() << endl;
	  cout << "Director: " << movie->getDirector() << endl;
	  cout << "Duration: " << movie->getDuration() << endl;
	  cout << "Rating: " << movie->getRating() << endl;
	}
	found = true;
      }
    }
    if (found == false) { //if nothing is found
      cout << "Nothing found." << endl;
    }
  }
  else if (strcmp(search, "YEAR") == 0) { //search by year
    //take in user input
    int year;
    cout << "Enter the year you want to search for: " << endl;
    cin >> year; //take in user command
    cin.get();
    bool found = false;
    for (int i = 0; i < Database->size(); i++) {
      if (Database->at(i)->getYear() == year) {
	if (Database->at(i)->getType() == 1) { //video game
	  Game* game = static_cast<Game*>(Database->at(i)); //cast to Game
	  cout << "Media found!" << endl;
	  cout << "Type: Video game" << endl;
	  cout << "Title: " << game->getTitle() << endl;
	  cout << "Year: " << game->getYear() << endl;
	  cout << "Publisher: " << game->getPublisher() << endl;
	  cout << "Rating: " << game->getRating() << endl;
	}
	if (Database->at(i)->getType() == 2) { //music
	  Music* music = static_cast<Music*>(Database->at(i)); //cast to Music
	  cout << "Media found!" << endl;
	  cout << "Type: Music" << endl;
	  cout << "Title: " << music->getTitle() << endl;
	  cout << "Year: " << music->getYear() << endl;
	  cout << "Artist: " << music->getArtist() << endl;
	  cout << "Duration: " << music->getDuration() << endl;
	  cout << "Publisher: " << music->getPublisher() << endl;
	}
	if (Database->at(i)->getType() == 3) { //movie
	  Movie* movie = static_cast<Movie*>(Database->at(i)); //cast to Movie
	  cout << "Media found!" << endl;
	  cout << "Type: Movie" << endl;
	  cout << "Title: " << movie->getTitle() << endl;
	  cout << "Year: " << movie->getYear() << endl;
	  cout << "Director: " << movie->getDirector() << endl;
	  cout << "Duration: " << movie->getDuration() << endl;
	  cout << "Rating: " << movie->getRating() << endl;
	}
	found = true;
      }
    }
    if (found == false) { //if not found
      cout << "Nothing found." << endl;
    }
    
  }
  else {
    cout << "Invalid input." << endl;
  }
}

void deleteMedia(vector<Media*> *Database) {
  //take in title or year
  cout << "Would you like to delete by title or year? Type \"TITLE\" or \"YEAR\"" << endl;
  char search[81];
  cin.getline(search, 80, '\n'); //take in user command
  if (strcmp(search, "TITLE") == 0) { //delete by title
    char title[81];
    cout << "Enter the title you want to delete: " << endl;
    cin.getline(title, 80, '\n'); //take in user command
    bool found = false;

    //use iterator
    vector<Media*>::iterator it;
    int index = 0;
    for (it = Database->begin(); it < Database->end(); it++) {
      if (strcmp((*it)->getTitle(), title) == 0) {
	found = true;
	cout << "Media found. Would like to delete \"" << (*it)->getTitle() << "\"? Type y/n" << endl;
	char del[81];
	cin.getline(del, 80, '\n');
	if (strcmp(del, "y") == 0) {
	  //delete media
	  delete *it;
	  Database->erase(Database->begin()+index);
	  cout << "Media deleted." << endl;
	  break;
	}
      }
      index++;
    }
    if (found == false) { //nothing found
      cout << "Nothing found." << endl;
    }
  }
  else if (strcmp(search, "YEAR") == 0) { //delete by year
    int year;
    cout << "Enter the year you want to search for: " << endl;
    cin >> year; //take in user command
    cin.get();
    bool found = false;

    //use iterator
    vector<Media*>::iterator it;
    int	index =	0;
    for	(it = Database->begin(); it < Database->end(); it++) {
      if ((*it)->getYear() == year) {
	found =	true;
	cout << "Media found. Would like to delete \"" << (*it)->getTitle() << "\"? Type y/n" << endl;
        char del[81];
        cin.getline(del, 80, '\n');
        if (strcmp(del, "y") == 0) {
	  //delete media
	  delete *it;
          Database->erase(Database->begin()+index);
          cout << "Media deleted." << endl;
          break;
        }
      }
      index++;
    }
    if (found == false) { //if nothing found
      cout << "Nothing found." << endl;
    }
    
  }
  else {
    cout << "Invalid input." << endl;
  }
}
