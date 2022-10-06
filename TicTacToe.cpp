/*This program creates a game of tic-tac-toe between two players
 *Author: Krishna Srikanth
 *Date: 10/6/22
 */

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

//set functions
void printBoard(int board[3][3]);
void makeBoard(int board[3][3]);
bool checkWin(int board[3][3], int player);
bool checkTie(int board[3][3]);

int main() {
  //initialize variables
  int board[3][3];
  int turn = 1;
  int xwins = 0;
  int owins = 0;

  //loop of one full game
  while(true) {
    makeBoard(board);
    char input[99];

    //loop of one move
    while(!checkWin(board, 1) && !checkWin(board, 2) && !checkTie(board)) {
      printBoard(board);

      //take in proper user input
      while(true) {
	//char input[3];
        cout << "Enter a letter followed by a number (ex. b1):" << endl;
        cin.getline(input, 98, '\n'); //take in user input
        if ((strlen(input) == 2 && input[0] == 'a' || input[0]== 'b' || input[0]== 'c') && (input[1] == '1' || input[1] == '2' || input[1] == '3')) {
	  break;
	}
	else {
	  cout << "That is not a valid spot." << endl;
	}
      }

      if (board[int(input[0]-97)][int(input[1]-49)] == 0) { //if the move is legal
	board[int(input[0]-97)][int(input[1]-49)] = turn; //update board
	//update turn
	if (turn == 1) {
	  turn = 2;
	}
	else if (turn == 2) {
	  turn = 1;
	}
      }
      else { //if the move is not legal
	cout << "That is not a valid spot." << endl;
      }
    
    }

    //game end conditions
    if (checkWin(board, 1)) { //if x wins
      cout << "X wins!" << endl;
      xwins++;
    }
    else if (checkWin(board, 2)) { //if o wins
      cout << "O wins!" << endl;
      owins++;
    }
    else if (checkTie(board)) { //if tie
      cout << "Tie!" << endl;
    }

    //print win counts
    cout << "X wins: " << xwins << "    O wins: " << owins << endl;

    //ask if users want to play again
    cout << "Would you like to play again? (y/n):" << endl;
    char playagain[99];
    cin.getline(playagain, 98, '\n');
    
    if (playagain[0] != 'y') {
      break;
    }
  }
  return 0;
}


void makeBoard(int board[3][3]) {
  //set all positions of board to 0
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = 0;
    }
  }
  return;
}

void printBoard(int board[3][3]) {
  cout << "  1 2 3" << endl; //print 1, 2, and 3
  for (int i = 0; i < 3; i++) {
    cout << char(97 + i); //print a, b, and c
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) { //if board spot is empty
	cout << "  ";
      }
      if (board[i][j] == 1) { //if board spot is x
	cout << " X";
      }
      if (board[i][j] == 2) { //if board spot is o
	cout << " O";
      }
    }
    cout << endl;
  }
}

bool checkWin(int board[3][3], int player) {
  for (int i = 0; i < 3; i++) {
    //check horizontals
    if ((board[i][0] == player) && (board[i][1] == player) && (board[i][2] == player)) {
      return true;
    }
    //check verticals
    if ((board[0][i] == player) && (board[1][i] == player) && (board[2][i] == player)) {
      return true;
    }
  }
  
  //check diagonals
  if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
    return true;
  }
  if ((board[2][0] == player) && (board[1][1] == player) && (board[0][2] == player)) {
    return true;
  }

  return false;
}

bool checkTie(int board[3][3]) {
  //if any spots are empty, return false
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 0) {
	return false;
      }
    }
  }
  
  return true;
}
