/*This program creates a shunting yard algorithm
 *Author: Krishna Srikanth
 *Date:
 */

#include <bits/stdc++.h>
#include "node.h"

using namespace std;

int main() {
  //user command loop
  while(true) {

    //take user input
    cout << "Type \"ADD\", \"PRINT\", \"DELETE\", \"AVERAGE\", or \"QUIT\"" << endl;
    char input[81];
    cin.getline(input, 80, '\n'); //take in user command

    //add
    if (strcmp(input, "ADD") == 0) {
      addStudent(head);
    }
  }
  return 0;
}
