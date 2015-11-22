#ifndef RHOMBUS_H
#define RHOMBUS_H

#include"Shape.h"

class Rhombus :public Shape
{
private:
	int diagonal;

public:

	Rhombus(int d, string desc = "Generic Rhombus");

	int getdiagonal();
	void setdiagonal(int d);

	virtual void scale(int n);
	virtual double computegeometricarea()const;
	virtual double computegeometricperimeter()const;
	virtual long computescreenarea()const;
	virtual long computescreenperimeter()const;
	virtual int Boundhorizontal() const;
	virtual int Boundvertical() const;
	virtual void draw(int c, int r, Canvas &canvas, char ch = '*')const;
	virtual ~Rhombus();
};



#endif