#include "Rectangle.h"
#include<iostream>
#include<string>
using namespace std;

int Rectangle::getwidth()const
{
	return width;
}
int Rectangle::getheight()const
{
	return height;
}
void Rectangle::setwidth(int w)
{
	width = w;
}
void Rectangle::setheight(int h)
{
	height = h;
}

Rectangle::Rectangle(int w, int h, string description) : width(w), height(h), Shape(typeid(this).name(), description){} //Constructor with height and description

void Rectangle::scale(int n) //Scale function 
{
	if (width + n >= 1 && height + n >= 1)
	{
		setwidth(getwidth() + n);
		setheight(getheight() + n);
	}
}
double Rectangle::computegeometricarea()const //geometric area for the shape
{
	return getwidth()*getheight();
}
double Rectangle::computegeometricperimeter()const //Geometric perimeter for the shape
{
	return 2 * (getwidth() + getheight());
}
long Rectangle::computescreenarea()const //Screen area covered by the shape
{
	return getwidth()*getheight();
}
long Rectangle::computescreenperimeter()const //screen perimeter covered by the shape
{
	return 2 * (getwidth() + getheight()) - 4;
}
int Rectangle::Boundhorizontal() const
{
	return getwidth();
}
int Rectangle::Boundvertical() const
{
	return getheight();
}

void Rectangle::draw(int c, int r, Canvas &canvas, char ch)const{
	for (int i = r; i < r + height; i++)
	{
		for (int j = c; j < c + width; j++)
			canvas.putCharacter(j, i, ch); // Adding character 'ch' at perticular index
	}

}

Rectangle::~Rectangle()
{
	//cout << "Rectangle" << endl;
}