#ifndef  WORDVEC_H
#define  WORDVEC_H
#include  <iostream>
#include  <vector>
#include  <string>
#include <algorithm>
#include<numeric>
#include "MyPair.h"

using namespace std;

class NameVector
{
public:
NameVector(istream& inputStream); //Name Vector constructor
void insert(const string& name); // Insert function to insert name in Vector	
bool remove(const string& name);  // Remove function to erase name from vector
int lookup(const string& name)  const; // Lookup function 
void print()const; //Print all contents of Vector
int size()  const; // Return size of the Vector
int sum_frequency_count()  const; // returns total name frequency count
void operator()(string name); //Function object
void operator()(MyPair<string,int> tempmap);//Function object to print contents
int operator()(int i, MyPair<string, int> temppair2);//Function object to CALCUALTE sum frequency count
void sort();// sort elements in vector

struct Compare //Compare String to find name in vector
{
  Compare(string val) : val_(val) {}
  bool operator()(const std::pair<string,int>& elem) const {
    return val_ == elem.first;
  }
  private:
    string val_;
};

private:
	vector<MyPair<string,int>> namevec; //vector object
};
#endif
