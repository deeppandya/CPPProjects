#include "NameMap.h"

NameMap::NameMap(istream& inputStream)
{
	istream_iterator<string> start(inputStream),finish;
	*this=for_each(start,finish,*this); //*this calls the function object
}
void NameMap::insert(const string& name)
{
	auto it=wordmap.find(name); // Find position for the given name
	if(it!=wordmap.end())
	{
		it->second=it->second+1; //Increment the frequency
	}
	else
	{
		wordmap.insert(pair<string,int>(name,1)); //Insert name with initial frequency of 1
	}
}
bool NameMap::remove(const string& name)
{
	auto it=wordmap.find(name); // Find position for the given name
	if(it!=wordmap.end())
	{
		wordmap.erase (it); // Erase name from the map at given position
		return true;
	}
	else
	{
		//cout<<"Name is not found in wordmap"<<endl;
		return false;
	}
	   
}
int NameMap::lookup(const string& name)  const
{
	auto it=wordmap.find(name); // Find position for the given name
	if(it!=wordmap.end())
	{
		return it->second; // return frequency of the given name 
	}
	else
	{
		//cout<<"Name is not found in wordmap"<<endl;
		return 0;
	}
}
void NameMap::print() const
{
	//for(auto it=wordmap.begin();it!=wordmap.end();++it)
	//{
	//	cout<<it->second<<" : "<<it->first<<endl; //Print map content
	//}
	for_each(wordmap.begin(),wordmap.end(),*this); //Print map content
}
int NameMap::size() const
{
	return wordmap.size(); //returns map size
}
int NameMap::sum_frequency_count()  const
{
	int count=0;
	/*for(pair<string,int> temppair:wordmap)
	{
		count+=temppair.second;
	}
	return count;*/ //returns total frequency count
	return accumulate(wordmap.begin(), wordmap.end(), count, *this); //returns total frequency count
}

void NameMap::operator()(string name)
{
	insert(name); //insert name in map
}

int NameMap::operator()(int i, pair<string, int> temppair2) 
{
	i = i + temppair2.second;
	return i; // Calculate Frequancy count
}
void NameMap::operator()(pair<string,int> tempmap)
{
	cout<<tempmap.second<<" : "<<tempmap.first<<endl; //Print map content
}