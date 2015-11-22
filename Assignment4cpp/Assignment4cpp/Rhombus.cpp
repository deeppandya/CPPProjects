#include "Rhombus.h"
#include<iostream>
#include<string>
using namespace std;

Rhombus::Rhombus(int d, string desc) :diagonal(d), Shape(typeid(this).name(), desc){}

int Rhombus::getdiagonal()
{
	return diagonal;
}
void Rhombus::setdiagonal(int d)
{
	diagonal = d;
}

void Rhombus::scale(int n)//scale function
{
	if (diagonal + n >= 1)
	{
		diagonal = diagonal + n;
	}
}
double Rhombus::computegeometricarea()const //Geometric area for the shape
{
	return (diagonal*diagonal) / 2;
}
double Rhombus:: computegeometricperimeter()const //Geometric perimeter for the shape
{
	return (2 * sqrt(2))*diagonal;
}
long Rhombus::computescreenarea()const //Screen area covered by the shape
{
	int n = floor(diagonal / 2);
	return (2 * n*(n + 1)) + 1;
}
long Rhombus::computescreenperimeter()const //screen perimeter covered by the shape
{
	return 2 * (diagonal - 1);
}
int Rhombus::Boundhorizontal() const
{
	return diagonal;
}
int Rhombus::Boundvertical() const
{
	return diagonal;
}

void Rhombus::draw(int c, int r, Canvas &canvas, char ch)const{
	int middle = ceil((float)diagonal / 2);			//finding the middle row
	int start = c;
	int end = c + diagonal;

	for (int i = r + middle; i < r + diagonal; i++)	//for the lower half
	{
		for (int j = start; j < end; j++)
			canvas.putCharacter(j, i, ch);
		start++; end--;									//decreasing the start and end after every loop
	}
	
	start = c; end = c + diagonal;
	start++; end--;

	for (int i = (r + middle - 1); i >= r; i--)				//for the upper half
	{
		for (int j = start; j < end; j++)
			canvas.putCharacter(j, i, ch);
		start++; end--;									//decreasing the start and end after every loop
	}
}

Rhombus::~Rhombus()
{
	//cout << "Rhombus" << endl;
}