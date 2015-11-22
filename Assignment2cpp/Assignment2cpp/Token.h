#ifndef Token_HEADER
#define Token_HEADER

#include<iostream>
#include <string>
#include<fstream>
#include<ostream>
#include<vector>
#include<sstream>
#include "Vector.h"

using namespace std;

class Token
{
private:
	//Token String
	string tokenName;
	//Token Frequency
	int frequency;
	//List of linenumbers for perticular Token
	Vector lineNumbers;

public: 
	//Default Constructor
	Token();
	//Constructor with token name and line number
	Token(string, int);
	//Setter function to set Token String
	void setTokenName(string name);
	//Getter function to Get Token String
	string getTokenName();
	//Setter function to set Token Frequency
	void setTokenFrequency(int);
	//Getter function to set Token Frequency
	int getTokenFrequency();
	//Function to add line number for perticular Token
	void addLineNumber(int);
	//Function to Get List of line numbers for perticular Token
	Vector getLineNumbers();
	//Check given token is euivalent or not
	bool isEquivalent(const Token&)const;
	//operator<< overloading to print token on screen
	friend ostream& operator<<(ostream&, const Token&);
	//operator<< overloading to print token to an external file
	friend ofstream& operator<<(ofstream& fout, const Token& token);

	//Destructor
	~Token();
};

#endif