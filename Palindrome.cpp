#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

int main() {
  //initializing char arrays
  char input[81];
  char phrase[81];
  
  cout << "This is a Palindrome checker! Enter up to 80 characters:" << endl;
  cin.getline(input, 80, '\n'); //take in user input
  
  //taking out punctuation and spaces
  int size = 0; //variable for size of inputted phrase
  for (int i = 0; i < 81; i++) {
    if (isalnum(input[i]) || input[i] == '\0') {
      phrase[size] = input[i];
      size++;
    }
    if (input[i] == '\0') {
      break;
    }
  }

  //creating the char array that will be compared with its reverse
  char compare[size+1];
  for (int i = 0; i < size; i++) {
    compare[i] = tolower(phrase[i]);
  }

  //checking if palindrome
  bool palindrome = true;
  for (int i = 0; i < size - 2; i++) {
    if (compare[i] != compare[size-2-i]) {
      palindrome = false;
    }
  }

  //print if the input is a palindrome or not
  if (palindrome == true) {
    cout << "Your phrase is a palindrome." << endl;
  }
  else {
    cout << "Your phrase is not a palindrome." << endl;
  }
    
  return 0;
}
