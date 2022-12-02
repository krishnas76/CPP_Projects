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
	//add a video game
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
	Game* game = new Game(title, year, publisher, rating);
	Database->push_back(game);
	cout << "Game added to database." << endl;
      }
      else if (strcmp(type, "MUSIC") == 0) {
	//add music
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
	cout << "Duration:  ";
        cin >> duration;
        cin.get();
        cout << "Publisher:  ";
        cin.get(publisher, 80);
        cin.get();
        Music* music = new Music(title, year, artist, duration, publisher);
        Database->push_back(music);
        cout << "Music added to database." << endl;

      }
      else if (strcmp(type, "MOVIE") == 0) {
	//add movie
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
        cout << "Duration:  ";
        cin >> duration;
        cin.get();
        cout << "Rating:  ";
        cin >> rating;
        cin.get();
        Movie* movie = new Movie(title, year, director, duration, rating);
        Database->push_back(movie);
        cout << "Movie added to database." << endl;

      }
      else {
	cout << "Invalid input." << endl;
      }
    }

    //search
    else if (strcmp(input, "SEARCH") == 0) {
      cout << "Would you like to search by title or year? Type \"TITLE\" or \"YEAR\"" << endl;
      char search[81];
      cin.getline(search, 80, '\n'); //take in user command
      if (strcmp(search, "TITLE") == 0) {
	char title[81];
	cout << "Enter the title you want to search for: " << endl;
	cin.getline(title, 80, '\n'); //take in user command
	bool found = false;
	for (int i = 0; i < Database->size(); i++) {
	  if (strcmp(Database->at(i)->getTitle(), title) == 0) {
	    if (Database->at(i)->getType() == 1) { //video game
	      Game* game = static_cast<Game*>(Database->at(i));
	      cout << "Media found!" << endl;
	      cout << "Type: Video game" << endl;
	      cout << "Title: " << game->getTitle() << endl;
	      cout << "Year: " << game->getYear() << endl;
	      cout << "Publisher: " << game->getPublisher() << endl;
	      cout << "Rating: " << game->getRating() << endl;
	    }
	    if (Database->at(i)->getType() == 2) { //music
	      Music* music = static_cast<Music*>(Database->at(i));
              cout << "Media found!" << endl;
              cout << "Type: Music" << endl;
              cout << "Title: " << music->getTitle() << endl;
              cout << "Year: " << music->getYear() << endl;
	      cout << "Artist: " << music->getArtist() << endl;
	      cout << "Duration: " << music->getDuration() << endl;
              cout << "Publisher: " << music->getPublisher() << endl;
            }
	    if (Database->at(i)->getType() == 3) { //movie
	      Movie* movie = static_cast<Movie*>(Database->at(i));
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
	if (found == false) {
	  cout << "Nothing found." << endl;
	}
      }
      else if (strcmp(search, "YEAR") == 0) {
	int year[81];
        cout << "Enter the title you want to search for: " << endl;
        cin.getline(year, 80, '\n'); //take in user command
        bool found = false;
        for (int i = 0; i < Database->size(); i++) {
          if (strcmp(Database->at(i)->getTitle(), title) == 0) {
            if (Database->at(i)->getType() == 1) { //video game
              Game* game = static_cast<Game*>(Database->at(i));
              cout << "Media found!" << endl;
              cout << "Type: Video game" << endl;
              cout << "Title: " << game->getTitle() << endl;
              cout << "Year: " << game->getYear() << endl;
              cout << "Publisher: " << game->getPublisher() << endl;
              cout << "Rating: " << game->getRating() << endl;
            }
            if (Database->at(i)->getType() == 2) { //music
              Music* music = static_cast<Music*>(Database->at(i));
              cout << "Media found!" << endl;
              cout << "Type: Music" << endl;
              cout << "Title: " << music->getTitle() << endl;
              cout << "Year: " << music->getYear() << endl;
              cout << "Artist: " << music->getArtist() << endl;
              cout << "Duration: " << music->getDuration() << endl;
              cout << "Publisher: " << music->getPublisher() << endl;
            }
            if (Database->at(i)->getType() == 3) { //movie
              Movie* movie = static_cast<Movie*>(Database->at(i));
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
        if (found == false) {
          cout << "Nothing found." << endl;
        }

      }
      else {
	cout << "Invalid input." << endl;
      }

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
