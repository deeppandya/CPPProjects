#ifndef SHAPE_H
#define SHAPE_H

#include<string>
#include "Canvas.h"
using namespace std;

class Shape
{
private:
	static int ID; //static shape ID
	long shapeid; //shape id
	string genericname;
	string descriptivename;

protected:
	Shape();
	Shape(string genericname, string descname); //constructor with generic name and descriptive name
	long getid() const;
	string getshapename() const; // Get function for shape name
	string getdescriptivename() const; // Get function for Descriptive name

	void setdescriptivename(string name); // Set function for Descriptive name
	string toString() const;

	virtual void scale(int n) = 0;
	virtual double computegeometricarea() const = 0;
	virtual double computegeometricperimeter() const = 0;
	virtual long computescreenarea() const = 0;
	virtual long computescreenperimeter() const = 0;
	virtual int Boundhorizontal() const = 0;
	virtual int Boundvertical() const = 0;
	virtual void draw(int c, int r, Canvas &canvas, char ch = '*')const = 0;
	virtual ~Shape();

	friend ostream& operator<<(ostream& out, Shape& shp); //Operator Overloading for <<
};

#endif