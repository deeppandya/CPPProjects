#include "NameMultiSet.h"

NameMultiSet::NameMultiSet(istream& inputStream)
{
	istream_iterator<string> start(inputStream),finish;
	*this=for_each(start,finish,*this); //*this calls the function object
}
void NameMultiSet::insert(const string& name)
{
	auto it=wordmultiset.find(name); // Find position for the given name
	if(it!=wordmultiset.end())
	{
		wordmultiset.insert(it,name); //Insert name at it position
	}
	else
	{
		wordmultiset.insert(name); //Insert name in multiset
	}
	

}
bool NameMultiSet::remove(const string& name)
{
	auto it=wordmultiset.find(name); // Find position for the given name
	if(it!=wordmultiset.end())
	{
		wordmultiset.erase (name); // Erase name from the map at given position
		return true;
	}
	else
	{
		//cout<<"Name is not found in wordmap"<<endl;
		return false;
	}
}
int NameMultiSet::lookup(const string& name)  const
{
	//look for a range of consecutive elements that represent the given name
	auto p=wordmultiset.equal_range(name);
	//compute the distance between the iterators that bound the range 
	int count=std::distance(p.first,p.second); 
	return count;

}
void NameMultiSet::print()const //Print Multiset content
{
	for(auto it=wordmultiset.begin();it!=wordmultiset.end();++it)
	{
		auto p=wordmultiset.equal_range(*it);
		cout<<lookup(*it)<<" : "<<*it<<endl;
		if(p.second==wordmultiset.end())
		{
			break;
		}
		else
		{
			it=p.second;
		}
	}
}
int NameMultiSet::size()  const
{
	return wordmultiset.size(); //returns multiset size
}
void NameMultiSet::operator()(string name)
{
	insert(name); //insert name in multiset
}