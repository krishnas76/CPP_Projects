/*This program creates a max heap.
 *Author: Krishna Srikanth
 *Date: 3/5/23
 */

#include <bits/stdc++.h>
#include "heap.h"

using namespace std;

int main() {
  
  //see if user wants to input manually or from file
  cout << "Would you like to input numbers manually or from a file? Type \"MANUAL\" or \"FILE\"" << endl;
  char input[81];
  cin.getline(input, 80, '\n');
  
  if (strcmp(input, "MANUAL") == 0 || strcmp(input, "FILE") == 0) {
    //initialize numbers array and count
    int numbers[100];
    int count = 0;
    
    //manual
    if (strcmp(input, "MANUAL") == 0) {
      //take in count of numbers user wants to enter
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
      for (int i = 0; i < count; i++) {
	cin >> numbers[i];
      }
      cin.ignore(50, '\n');
    }
    
    //file
    else if (strcmp(input, "FILE") == 0) {
      //take in numbers from file
      cout << "Enter file name:" << endl;
      char filename[81];
      cin.getline(filename, 80, '\n');
      ifstream numberfile(filename);
      for (int i = 0; i < 100; i++) {
	if (numberfile.eof()) {
	  break;
	}
	numberfile >> numbers[i];
	count++;
      }
    }

    //create heap with the inputted numbers
    Heap* heap = new Heap(count);
    for (int i = 0; i < count; i++) {
      heap->add(numbers[i]);
    }

    //command loop
    while(true) {
      //get user command
      cout << "Type \"REMOVE\" to remove the maximum value, \"RALL\" to remove all values, and \"PRINT\" to print the current heap." << endl;
      char input[81];
      cin.getline(input, 80, '\n');

      //remove max value
      if (strcmp(input, "REMOVE") == 0) {
	int output = heap->removeMax();

	//if heap is empty
	if (output == INT_MIN) {
	  cout << "Heap is empty" << endl;
	}

	//if a value has been removed
	else {
	  cout << "You removed the max value of " << output << endl;
	}
      }

      //remove all
      else if (strcmp(input, "RALL") == 0) {
	int output = INT_MIN;
	//iterate through maximum size of heap (100)
	for (int i = 0; i < 100; i++) {
	  //remove max value
	  output = heap->removeMax();

	  //if we have reached the end of the heap
	  if (output == INT_MIN) {
	    break;
	  }

	  cout << output << " ";
	}
	break;
      }

      //print
      else if (strcmp(input, "PRINT") == 0) {
	heap->print(1, 0);
      }
      
      //invalid input
      else {
	cout << "Invalid input." << endl;
      }
    }
    
  }
  
  //invalid input
  else {
    cout << "Invalid input." << endl;
  }
  
  return 0;
}
