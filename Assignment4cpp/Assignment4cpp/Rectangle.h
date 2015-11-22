#ifndef RECTANGLE_H
#define RECTANGLE_H
#include"Shape.h"

class Rectangle :public Shape
{
private:
	int width;
	int height;

public:
	int getwidth()const;
	int getheight()const;
	void setwidth(int w);
	void setheight(int h);

	Rectangle();
	Rectangle(int w, int h, string description = "Generic Rectangle");

	virtual void scale(int n);
	virtual double computegeometricarea()const;
	virtual double computegeometricperimeter()const;
	virtual long computescreenarea()const;
	virtual long computescreenperimeter()const;
	virtual int Boundhorizontal() const;
	virtual int Boundvertical() const;
	virtual void draw(int c, int r, Canvas &canvas, char ch = '*')const;
	virtual ~Rectangle();
};

#endif