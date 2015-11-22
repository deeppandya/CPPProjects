#include<iostream>
#include<string>
using namespace std;
#include"BorderedCanvas.h"

BorderedCanvas::BorderedCanvas(int w, int h) :Canvas(w, h){
	decorateClientArea();
}

void BorderedCanvas::clearClientArea(char ch){
	int row = geth() + 2;		//increasing number of rows by 2 which are needed for borders
	int col = getw() + 2;		//increasing number of columns by 2 which are needed for borders

	for (int i = 1; i <row - 1; i++)
	for (int j = 1; j <col - 1; j++)
		clientarea[i][j] = ch;
}

void BorderedCanvas::putCharacter(int c, int r, char ch){
	int row = geth() + 2;
	int col = getw() + 2;

	for (int i = 1; i < row; i++)			//starting from the 1st row from where the client area begins
	for (int j = 1; j < col; j++)		//starting from the 1st column from where the client area begins
	if (i == r + 1 && j == c + 1)
		clientarea[i][j] = ch;
}


void BorderedCanvas::decorateClientArea(){
	clientarea.clear();			//clear the client area

	int row = geth() + 2;		//increasing number of rows by 2 which are needed for borders
	int col = getw() + 2;		//increasing number of columns by 2 which are needed for borders
	vector<char> temprow;
	for (int i = 0; i < row; i++){
		temprow.clear();		//clearing temperary row after each iteration
		for (int j = 0; j < col; j++){
			if ((i == 0 && j == 0) || (i == 0 && j == col - 1) || (i == row - 1 && j == 0) || (i == row - 1 && j == col - 1))
				temprow.push_back('+');
			else if (j == 0 || j == col - 1)
				temprow.push_back('|');
			else if (i == 0 || i == row - 1)
				temprow.push_back('-');
			else
				temprow.push_back(' ');

		}
		clientarea.push_back(temprow);	//Adding temperary row vector after every iteration
	}
}

char BorderedCanvas::getCharacter(int c, int r) const{
	int row = geth() + 2;
	int col = getw() + 2;

	for (int i = 1; i < row; i++)			//starting from the 1st row from where the client area begins
	{
		for (int j = 1; j < col; j++)		//starting from the 1st column from where the client area begins
		{
			if (i == r + 1 && j == c + 1)
			{
				return clientarea[i][j];
				break;
			}
		}
	}
	return ' ';
}

BorderedCanvas::~BorderedCanvas()
{
	//cout << "Bordered Canvas" << endl;
}