/*This program creates a guessing game where the user guesses a random generated number from 1 to 100
 *Author: Krishna Srikanth
 *Date: 9/12/22
 *
 *3 Rules for the c++ class:
 *No global variables
 *No strings
 *Include <iotream>, not stdio
 */

#include <iostream>

using namespace std;

int main()
{
  while (true) {
    cout << "Welcome to Guessing Game." << endl;
    //make the random number from 1 to 100
    srand(time(0));
    int number = rand() % 100 + 1;
    
    int guesses = 0;

    //main game function
    while (true) {
      //taking in user guess
      cout << "Guess a number:" << endl;
      int input = 0;
      cin >> input;
      cin.ignore(1, '\n'); //ignore the new line character when taking input

      guesses++;
      if (input == number) { //if the user guessed right
	break;
      }
      if (input < number) { //if the guess is too low
	cout << "That is too low." << endl;
      }
      if (input > number) { //if the user guess too high
	cout << "That is too high." << endl;
      }
    }
    //finishing game and asking to play again
    cout << "You guessed the number in ";
    cout << guesses;
    cout << " guesses!" << endl;
    cout << "Would you like to play again? Enter 1 for yes or 0 for no." << endl;
    int input = 0;
    cin >> input;
    cin.ignore(1, '\n');
    if (input != 1) { //if user doesnt want to play again, break from the game loop
      break;
    }
  }
  return 0;
}
