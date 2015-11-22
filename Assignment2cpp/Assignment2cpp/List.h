#ifndef LIST_H
#define LIST_H

#include "Token.h"
#include <iostream>

using namespace std;

class List
{
	// Node structure to store Token and it's next node's pointer
	struct Node
	{
		//Token Data
		Token data;
		//Next pointer
		Node* next;

		//NOde constructor
		Node(const Token&, Node*);

	};
	//first points to first node
	Node* first;
	//Temp Pointer
	Node* point;
	//length of node list
	int length = 0;

public:

	//Default constructor
	List();
	//Copy constructor
	List(const List&);
	//operator= overloading
	void operator=(const List&);
	//Destructor
	~List();
	//function to get list's size
	int size() const;
	//Function to insert Token
	void insert(const Token&);
	//Function to lookup for a token
	Token* lookup(const Token&) const;
	// Function to get first node pointer from NOde list
	Node* getFirstNode();
	//Function to print list
	void printList();
	//Function to Write List data into external file
	void WriteList(ofstream& fout);

	//friend function to overload operator<<
	friend ostream& operator<<(ostream&, const List&);
};
#endif