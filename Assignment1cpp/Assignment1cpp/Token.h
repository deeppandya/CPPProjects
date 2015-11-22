#ifndef Token_HEADER
#define Token_HEADER

#include<iostream>
#include <string>
#include<fstream>
#include<ostream>
#include<vector>
#include<sstream>

using namespace std;

class Token
{
private:
	//Token String
	string tokenName;
	//Token Frequency
	int frequency;
	//List of linenumbers for perticular Token
	vector<int> lineNumbers;

public: 

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
	vector<int> getLineNumbers();	
};

#endif