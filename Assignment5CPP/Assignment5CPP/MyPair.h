#ifndef  MYPAIR_H
#define  MYPAIR_H
#include  <string>
#include  <utility>

template<class K,  class V> 
class MyPair:  public std::pair<K,V>
{
public:
	MyPair(){};
	MyPair(const K& x,  const V& y)  :std::pair<K,V>(x,y)  {}
	//delegate to base class ctor

	//operator==overload.
	//Called by algorithms like find, but can be called
	//anywhere objects of MyPair<K,V> are required to be compared for equality.
	friend  bool  operator==(const MyPair& p1,  const MyPair& p2)
	{
	//Implement our definition of "MyPairp1==MyPairp2".
	//requires that implements operator=
	return p1.first==p2.first;
	}

	//operator()overload.
	//Called by the sort algorithm in this assignment,
	//but can be used anywhere objects of MyPair<K,V> are required to act as binary
	//functions with the following prototype.
	bool  operator()  (const MyPair& p1,  const MyPair& p2)
	{
	//Implement our definition of "MyPairp1<MyPairp2".
	//requires that type implements operator<
	return  (p1.first<p2.first);
	}
};
#endif
