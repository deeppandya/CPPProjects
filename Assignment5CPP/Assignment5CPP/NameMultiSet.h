#ifndef  WORDMULTISET_H
#define  WORDMULTISET_H
#include  <iostream>
#include  <map>
#include  <string>
#include <algorithm>
#include <iterator>
#include <set>
//#include "MyPair.h"

using namespace std;

class NameMultiSet
{
public:
class CompareNames //Class to declare function object
{
public:
//Returns (s1<s2) if s1 and s2 have the same length;
//otherwise,returns (s1.length()<s2.length()).
	bool  operator()(string s1,string s2)
	{
		if(s1.length()==s2.length())
		{
			return s1<s2;
		}
		else
		{
			return s1.length()<s2.length();
		}
	}
};



NameMultiSet(istream& inputStream); // Name multiset constructor
void insert(const string& name); // Insert function to insert name in multiset	
bool remove(const string& name);  // Remove function to erase name from multiset
int lookup(const string& name)  const; // Lookup function 
void print()const; //Print all contents of multiset
int size()  const; // Return size of the multiset
void operator()(string name); //Function object

private:

	multiset<string,CompareNames> wordmultiset;//Multiset object

};
#endif