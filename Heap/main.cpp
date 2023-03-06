/*This program creates a max heap.
 *Author: Krishna Srikanth
 *Date:
 */

#include <bits/stdc++.h>

using namespace std;

int main() {

  //see if user wants to input manually or from file
  cout << "Would you like to input numbers manually or from a file? Type \"MANUAL\" or \"FILE\"" << endl;
  char input[81];
  cin.getline(input, 80, '\n');

  //manual
  if (strcmp(input, "MANUAL") == 0) {
    //take in count of numbers user wants to enter
    int count;
    while(true) {
      cout << "How many numbers would you like to enter? (up to 100)" << endl;
      cin >> count;
      cin.ignore(50, '\n');
      if (count <= 100) {
	break;
      }
      else {
	cout << "You can only enter up to 100 numbers." << endl;
      }
    }

    //take in numbers separated by spaces
    cout << "Enter your numbers separated by spaces: " << endl;
    int numbers[count];
    for (int i = 0; i < count; i++) {
      cin >> numbers[i];
    }


    
  }

  //file
  else if (strcmp(input, "FILE") == 0) {
    //take in numbers from file
    cout << "Enter file name:" << endl;
    char filename[81];
    cin.getline(filename, 80, '\n');
    ifstream numberfile(filename);
    int numbers[100];
    int count = 0;
    for (int i = 0; i < 100; i++) {
      if (numberfile.eof()) {
	break;
      }
      numberfile >> numbers[i];
      count++;
    }

    
    
  }

  //invalid input
  else {
    cout << "Invalid input." << endl;
  }




  return 0;
}
