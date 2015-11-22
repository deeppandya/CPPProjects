#include<iostream>
#include<cassert>
#include"Vector.h"
using namespace std;
Vector::Vector(){
	capacity = 1;
	store = new int[capacity];
	next_Index = 0;
}
Vector::Vector(int initial_Size){
	capacity = initial_Size;
	store = new int[capacity];
	next_Index = 0;
}
Vector::Vector(const Vector & v) : capacity(v.capacity), next_Index(v.next_Index), store(v.store){}
Vector::~Vector(){

	//delete[] store;
}
bool Vector::isempty(){
	return (store == nullptr);
}
void Vector::operator=(const Vector & v){
	capacity = v.capacity;
	next_Index = v.next_Index;
	store = v.store;
}
void Vector::resize(){
	capacity = capacity * 2;
	int* temp = new int[capacity];
	for (int i = 0; i<next_Index; i++) {
		temp[i] = store[i];
	}
	store = temp;
}
int Vector::size()const{

	return next_Index;
}
void Vector::push_Back(int s){
	if (next_Index == (capacity))
	{
		resize();
		store[next_Index] = s;
		next_Index++;
	}
	else{
		store[next_Index] = s;
		next_Index++;
	}
}
int Vector::pop_Back(){
	assert(!isempty());
	int value = store[next_Index - 1];
	next_Index--;
	return value;
}
int& Vector::operator[](int k){
	assert(!isempty());
	return store[k];
}
const int& Vector::operator[](int k)const{
	return store[k];
}
ostream& operator<<(ostream& out, const Vector & v){
	for (int i = 0; i < v.size(); ++i){
		out << v[i] << " ";
	}
	return out;
}