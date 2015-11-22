#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<typeinfo>
#include "Shape.h"

int Shape::ID = 1;

Shape::Shape(string genericname, string descname)
{
	this->genericname = genericname;
	setdescriptivename(descname);
	shapeid=ID++;
}

long Shape::getid() const
{
	return shapeid;
}
string Shape::getshapename() const //Function to get shape name
{
	return genericname;
}
string Shape::getdescriptivename() const //Function to get descriptive name
{
	return descriptivename;
}

void Shape::setdescriptivename(string name) //Function to set descriptive name 
{
	descriptivename = name;
}

string Shape::toString() const{ //Print info as a string

	ostringstream out;
	out << setprecision(2) << fixed;	//set the precision for double values
	out << "Shape Information" << endl << "-----------------" << endl;

	out << setw(17) << left;		//setw for proper alignment
	out << "Static Name : " << typeid(this).name();
	out << setw(18) << left;
	out << "\nDynamic Name : " << typeid(*this).name();
	out << setw(18) << left;
	out << "\nGeneric name: " << genericname;
	out << setw(18) << left;
	out << "\nDescription: " << descriptivename;
	out << setw(18) << left;
	out << "\nid: " << shapeid;
	out << setw(18) << left;
	out << "\nBound. box W : " << Boundhorizontal();
	out << setw(18) << left;
	out << "\nBound. box H : " << Boundvertical();
	out << setw(18) << left;
	out << "\nScr area: " << computescreenarea();
	out << setw(18) << left;
	out << "\nGeo area: " << computegeometricarea();
	out << setw(18) << left;
	out << "\nScr perimeter: " << computescreenperimeter();
	out << setw(18) << left;
	out << "\nGeo perimeter: " << computegeometricperimeter() << endl;

	return out.str();
}


ostream& operator<<(ostream& out, Shape& shape) // << Operator overloading 
{
	out << shape.toString();
	return out;
}

Shape::~Shape()
{
	//cout << "Shape" << endl;
}