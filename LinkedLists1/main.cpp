/*This program tests the Node class
 *Author: Krishna Srikanth
 *Date: 
 */

#include <iostream>
#include <cstring>
#include <ctype.h>
#include <vector>
#include <iomanip>
#include <algorithm>

#include "Student.h"
#include "Node.h"

using namespace std;

int main() {
  char boy1[] = "boy";
  Student* boy = new Student(boy1);
  char girl1[] = "girl";
  Student* girl = new Student(girl1);

  Node* boynode = new Node(boy);
  Node* girlnode = new Node(girl);
  boynode->setNext(girlnode);
  cout << boynode->getNext()->getStudent()->description << endl;
  delete boynode;
  delete girlnode;
  
  return 0;
}
