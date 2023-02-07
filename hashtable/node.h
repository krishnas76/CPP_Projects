#pragma once

// Jeff McMillan 1/6/23 C++
#include "student.h"

// This is a node of a linked list, containing students.
class Node {
	Student* stuptr; // Pointer to student data
	Node* nextptr; // Pointer to next node in list.

public:
	// Gets a pointer to next node
	Node* getNext() const;
	
	// Gets a pointer to the student this node contains.
	Student* getStudent();
	
	// Set the pointer to the next node.
	void setNext(Node*);
	
	// Construct a node with a pointer to data
	Node(Student*);
	
	// Delete this node and DELETE THE STUDENT IT CONTAINS!
	// This means once a student is put in a linked list, the list is managing that memory.
	~Node();

};
