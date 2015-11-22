#ifndef VECTOR_H_
#define VECTOR_H_
#include<iostream>
using namespace std;
class Vector{
private:
	int *store;
	int capacity;
	int next_Index;
	void resize();
	bool isempty();

public:
	//Default constructor
	Vector();
	//Constructor with initial size
	explicit Vector(int);
	//Copy constructor
	Vector(const Vector &);
	//Destructor
	~Vector();
	//Push given integer value at the end of int* store
	void push_Back(int);
	//Read last integer value from the int* store
	int pop_Back();
	//Function to get the size
	int size()const;
	//operator= overloading
	void operator=(const Vector&);
	//operator[] overloading
	int& operator[](int);
	//operator[] overloading with const values
	const int& operator[](int)const;
	//friend function to override operator<<
	friend ostream& operator<<(ostream&, const Vector&);
};
#endif