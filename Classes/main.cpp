/*This program creates a digital media database
 *Author: Krishna Srikanth
 *Date:
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>

#ifndef MEDIA_H
#define MEDIA_H
#include "Media.h"
#endif

using namespace std;

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
      
    }

    //print
    else if (strcmp(input, "SEARCH") == 0) {
      
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
