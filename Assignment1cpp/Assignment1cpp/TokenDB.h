#include<iostream>
#include <string>
#include<fstream>
#include<ostream>
#include<vector>
#include<sstream>
#include <list>
#include <array>
#include "Token.h"

using namespace std;

class TokenDB
{
private:

public:
	array<list<Token>,26> arr;
	
	void SetToken(const string &s, char delim, int linenum);
	string trim(const string & str);
	void assignList();
	void ReadFile(string);
	void Print();
	void ExportData();
	void lookup(string tokenstring);

	TokenDB(string);

};