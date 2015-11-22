#include "NameVector.h"

NameVector::NameVector(istream& inputStream)
{
	istream_iterator<string> start(inputStream),finish;
	*this=for_each(start,finish,*this); //*this calls the function object
}
void NameVector::insert(const string& name)
{
	MyPair<string,  int> p(name,  1);
	//p is the element object to look for by the find algorithm

	//look for an element equal top
	auto vit=find(namevec.begin(),namevec.end(),p);

	if(vit!=namevec.end()  )
	++vit->second;  //found:increment the frequency count of the found pair
	else
	namevec.push_back(p);	//not found:insert a new pair in the container
}
bool NameVector::remove(const string& name)
{
	 auto it = find_if (namevec.begin(), namevec.end(),Compare(name));
	 if(it!=namevec.end())
	 {
			namevec.erase(it);// erase an element 
			return true;
	 }
	 else
	 {
		 return false;
	 }
}
int NameVector::lookup(const string& name)  const
{
	//for(auto it=namevec.begin();it!=namevec.end();++it)
	//{
	//	if(it->first==name)
	//	{
	//		return it->second;// return frequency of the given name 
	//	}
	//}
	//return 0;
	auto it = find_if (namevec.begin(), namevec.end(),Compare(name));
	 if(it!=namevec.end())
	 {
			return it->second;
	 }
	 else
	 {
		 return 0;
	 }
}
void NameVector::print()const
{
	//for(auto it=namevec.begin();it!=namevec.end();++it)
	//{
	//	cout<<it->second<<" : "<<it->first<<endl; //Print vector content
	//}
	for_each(namevec.begin(),namevec.end(),*this); //Print map content
}

void NameVector::operator()(MyPair<string,int> tempmap)
{
	cout<<tempmap.second<<" : "<<tempmap.first<<endl; //Print map content
}

int NameVector::size()  const
{
	return	namevec.size(); //returns vector size
}
int NameVector::sum_frequency_count()  const
{
	int count=0;
	/*for(MyPair<string,int> temppair:namevec)
	{
		count+=temppair.second;
	}
	return count;*/  //returns total frequency count

	return accumulate(namevec.begin(), namevec.end(), count, *this); //returns total frequency count
}
void NameVector::sort()
{
	//uses operator() as defined
	std::sort(namevec.begin(),namevec.end(),MyPair<string,int>()); //Sort the elements in vector using function object of MyPair<string,int>
}

void NameVector::operator()(string name)
{
	insert(name); //insert name in vector
}

int NameVector::operator()(int i, MyPair<string, int> temppair2)
{
	i = i + temppair2.second;
	return i;
}