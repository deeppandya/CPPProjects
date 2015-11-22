#include<iostream>
#include"Canvas.h"

using namespace std;

Canvas::Canvas(int w, int h) :height(h), width(w){}
int Canvas::geth() const
{
	return height;
}
int Canvas::getw() const
{
	return width;
}
void Canvas::clearClientArea(char ch)
{
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++)
			clientarea[i][j] = ch;
	}
}
ostream& operator<<(ostream& out, Canvas& canvas){

	for (vector<vector<char>>::iterator it = canvas.clientarea.begin(); it != canvas.clientarea.end(); ++it){
		for (vector<char>::iterator jt = it->begin(); jt != it->end(); ++jt){
			out << *jt;
		}
		out << endl;
	}
	return out;
}

void Canvas::putCharacter(int col, int row, char ch){	//put the Character at particular index
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == row && j == col)
			{
				clientarea[i][j] = ch;
				break;
			}

		}
	}
}

char Canvas::getCharacter(int col, int row) const{		//get the Character at particlar index
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == row && j == col)
			{
				return clientarea[i][j];
				break;
			}
		}
	}return ' ';
}

void Canvas::decorateClientArea(){
	vector<char> temprow;		//temperary vector for rows
	for (int i = 0; i < height; i++)
	{
		temprow.clear();		//clear temperary vector after each iteration
		for (int j = 0; j < width; j++)
			temprow.push_back(' ');

		clientarea.push_back(temprow);		//add the temperary vector after every iteration

	}
}

Canvas::~Canvas()
{
	//cout << "Canvas" << endl;
}