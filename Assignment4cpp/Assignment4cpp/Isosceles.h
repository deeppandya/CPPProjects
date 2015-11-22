#ifndef ISOSCELES_H
#define ISOSCELES_H

#include"Shape.h"

class Isosceles :public Shape
{
private:
	int height;
	int b;
public:
	int getheight();
	void setheight(int h);

	Isosceles(int h, string desc = "Generic Isosceles Triangle");
	virtual void scale(int n);
	virtual double computegeometricarea()const;
	virtual double computegeometricperimeter()const;
	virtual long computescreenarea()const;
	virtual long computescreenperimeter()const;
	virtual int Boundhorizontal() const;
	virtual int Boundvertical() const;
	virtual void draw(int c, int r, Canvas &canvas, char ch = '*')const;
	virtual ~Isosceles();
};

#endif