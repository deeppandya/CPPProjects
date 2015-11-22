#include<iostream>
#include<string>
using namespace std;
#include"PlainCanvas.h"

PlainCanvas::PlainCanvas(int w, int h) :Canvas(w, h){
	decorateClientArea();
}

void PlainCanvas::clearClientArea(char ch){
	int row = geth();		//increasing number of rows by 2 which are needed for borders
	int col = getw();		//increasing number of columns by 2 which are needed for borders

	for (int i = 1; i <row - 1; i++)
	for (int j = 1; j <col - 1; j++)
		clientarea[i][j] = ch;
}

void PlainCanvas::putCharacter(int c, int r, char ch){
	int row = geth();
	int col = getw();

	for (int i = 1; i < row; i++)			//starting from the 1st row from where the client area begins
	for (int j = 1; j < col; j++)		//starting from the 1st column from where the client area begins
	if (i == r + 1 && j == c + 1)
		clientarea[i][j] = ch;
}


void PlainCanvas::decorateClientArea(){
	clientarea.clear();			//clear the client area

	int row = geth();
	int col = getw();
	vector<char> temprow;
	for (int i = 0; i < row; i++){
		temprow.clear();		//clearing temperary row after each iteration
		for (int j = 0; j < col; j++){
			temprow.push_back(' ');
		}
		clientarea.push_back(temprow);	//Adding temperary row vector after every iteration
	}
}

char PlainCanvas::getCharacter(int c, int r) const{
	int row = geth();
	int col = getw();

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
	}return ' ';
}

PlainCanvas::~PlainCanvas()
{
	//cout << " Plain Canvas" << endl;
}