#include<iostream>
#include <string>
#include<fstream>
#include<ostream>
#include<vector>
#include<sstream>
#include <list>
#include <array>
#include <cassert>
#include "List.h"
#include "Vector.h"
#include "Token.h"

using namespace std;

class TokenDB
{
private:

public:
	//array to store list of tokens
	array<List,26> arr;
	// Function to set token in TokenDB
	void SetToken(const string &s, char delim, int linenum);
	//Function to trim space and other punctuations from the string
	string trim(const string & str);
	//Assign default list 
	void assignList();
	//Read file from given input file
	void ReadFile(string);
	//Function to print on screen
	void Print();
	//Option to export data in to an external data
	void ExportData();
	//Function to lookup for a token
	void lookup(string tokenstring);
	//constructor with file name
	TokenDB(string);
	//Destructor
	~TokenDB();

};