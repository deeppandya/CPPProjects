#ifndef  WORDMAP_H
#define  WORDMAP_H
#include  <iostream>
#include  <map>
#include  <string>
#include <algorithm>
#include <iterator>
#include <numeric>
//#include "MyPair.h"

using namespace std;

class NameMap
{
public:
NameMap(istream& inputStream); //Name map constructor
void insert(const string& name); // Insert function to insert name in map	
bool remove(const string& name);  // Remove function to erase name from map
int lookup(const string& name)  const; // Lookup function 
void print()const; //Print all contents of map
int size()  const; // Return size of the map
int sum_frequency_count()  const; // returns total name frequency count
void operator()(string name); //Function object
void operator()(pair<string,int> tempmap);//Function object to print contents
int operator()(int i, pair<string, int> temppair2); //Function object to CALCUALTE sum frequency count
private:

	map<string,int> wordmap; //Map object
	
};
#endif