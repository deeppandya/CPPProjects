#include "RightIsosceles.h"
#include<iostream>
#include<string>
using namespace std;

int RightIsosceles::getheight()
{
	return height;
}
void RightIsosceles::setheight(int h)
{
	height = h;
}

RightIsosceles::RightIsosceles(int h, string desc ) :height(h), Shape(typeid(this).name(), desc){} //constructor with height and description

void RightIsosceles::scale(int n)
{
	if (height + n >= 1)
	{
		height = height + n;
		b = height + n;
	}
}
double RightIsosceles::computegeometricarea()const //Geometric area for the shape
{
	return (height*b) / 2;
}
double RightIsosceles::computegeometricperimeter()const //Geometric perimeter for the shape
{
	return height * (sqrt(2) + 2);
}
long RightIsosceles::computescreenarea()const //screen area covered by the shape
{
	return (height*(height + 1)) / 2;
}
long RightIsosceles::computescreenperimeter()const //screen perimeter covered by the shape
{
	return 3 * (height - 1);
}
int RightIsosceles::Boundhorizontal() const
{
	return b;
}
int RightIsosceles::Boundvertical() const
{
	return height;
}

void RightIsosceles::draw(int c, int r, Canvas &canvas, char ch)const {
	int end = c + height;
	for (int i = (r + height - 1); i >= r; i--)		//starting from the base row
	{
		for (int j = c; j < end; j++)
			canvas.putCharacter(j, i, ch);
		end--;												//decreasing end pointer after every loop
	}
}

RightIsosceles::~RightIsosceles()
{
	//cout << "Right Isosceles" << endl;
}