#include "Isosceles.h"
#include<iostream>
#include<string>
using namespace std;

int Isosceles::getheight()
{
	return height;
}
void Isosceles::setheight(int h)
{
	height = h;
}

Isosceles::Isosceles(int h, string desc) :height(h),b((2*h)-1), Shape(typeid(this).name(), desc){} //Constructor with height and description
void Isosceles::scale(int n)
{
	if (height + n >= 1)
	{
		height = height + n;
		b = 2 * height - 1;
	}
}
double Isosceles::computegeometricarea()const //Geo metric area of shape
{
	return (height*b) / 2;
}
double Isosceles::computegeometricperimeter()const //perimeter of the shape
{
	return b - (sqrt((0.25*b*b) + (height*height)));
}
long Isosceles::computescreenarea()const // screen area covered by shape
{
	return height*height;
}
long Isosceles::computescreenperimeter()const //screen perimeter convered by shape
{
	return 4 * (height - 1);
}
int Isosceles::Boundhorizontal() const
{
	return b;
}
int Isosceles::Boundvertical() const 
{
	return height;
}

void Isosceles::draw(int c, int r, Canvas& canvas, char ch) const{ 

	int start = c;
	int  end = c + b;
	for (int i = (r + height - 1); i >= r; i--)		//starting from base row
	{
		for (int j = start; j < end; j++)
			canvas.putCharacter(j, i, ch);
		start++; end--;								//decreasing start and end after every loop
	}

}

Isosceles::~Isosceles()
{
	//cout << "Isosceles " << endl;
}