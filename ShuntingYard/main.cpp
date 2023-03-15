/*This program creates a shunting yard algorithm
 *Author: Krishna Srikanth
 *Date:
 */

#include <bits/stdc++.h>
#include "node.h"

using namespace std;

int order(char a);

int main() {
  //user command loop
  while(true) {

    //take user input
    cout << "Write a mathematic expression with spaces in between each character:" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //translate to postfix
    LinkedList* stack = new LinkedList();
    LinkedList* queue = new LinkedList();
    for(int i=0; i < 2*(sizeof(input)/sizeof(input[0])); i++) {
      if (strcmp(input[i],'+') == 0 || strcmp(input[i],'-') == 0 || strcmp(input[i],'*') == 0 || strcmp(input[i],'/') == 0 || strcmp(input[i],'^') == 0 || strcmp(input[i],'(') == 0) {
	Node* operation = new Node(input[i]);
	if (order(operation)>order(stack->peek())) {
	  stack->push(operation);
	}
	else {
	  
	}
      }
    }
  }
  return 0;
}
