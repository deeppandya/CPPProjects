#include "FramedCanvas.h"
#include<iostream>
#include<string>
using namespace std;

FramedCanvas::FramedCanvas(int w, int h, string title) :title(title), Canvas(w, h)
{
	decorateClientArea();
}
void FramedCanvas::decorateClientArea()
{
	int row = geth() + 4;			//increasing number of rows by 4 beacause its framed canvas
	int col = getw() + 2;			//increasing number of columns by 2 beacause its framed canvas

	clientarea.clear();			//clear the client area earlier set by the base class

	vector<char> temprow;
	int i = 0;
	for (; i<2; i++) {			//filling the first two rows of frame
		temprow.clear();

		for (int j = 0; j<col; j++) {

			if ((i == 0 && j == 0) || (i == 0 && j == getw() + 2 - 1)) {
				temprow.push_back('+');
			}
			else if ((i == 1 && j == 0)){
				temprow.push_back('|');
				int len = 0;
				while (len != title.length()) {		//writing the frame title
					temprow.push_back(title[len]);
					len++;
				}

				j = len + 1;
				for (; j<col; j++) {
					if (j == col - 1) {
						temprow.push_back('|');
					}
					else{
						temprow.push_back(' ');
					}
				}
			}
			else{
				temprow.push_back('-');
			}
		}
		clientarea.push_back(temprow);
	}

	for (; i < row; i++){		//filling the last row 
		temprow.clear();
		for (int j = 0; j < col; j++){
			if ((i == 2 && j == 0) || (i == 2 && j == col - 1))
				temprow.push_back('|');
			else if ((i == row - 1 && j == 0) || (i == row - 1 && j == col - 1))
				temprow.push_back('+');
			else if (j == 0 || j == col - 1)
				temprow.push_back('|');
			else if (i == 2 || i == row - 1)
				temprow.push_back('-');
			else
				temprow.push_back(' ');
		}
		clientarea.push_back(temprow);
	}
}
void FramedCanvas::clearClientArea(char ch)
{
	for (int i = 3; i < geth() + 4 - 1; i++)		//starts from the 3rd row from where the client area begins
	for (int j = 1; j < getw() + 2 - 1; j++)		//starts from the 1st column from where the client area begins
		clientarea[i][j] = ch;
}
void FramedCanvas::putCharacter(int c, int r, char ch)
{
	int row = geth() + 4;			//increasing number of rows by 4 beacause its framed canvas
	int col = getw() + 2;			//increasing number of columns by 2 beacause its framed canvas

	for (int i = 3; i < row - 1; i++)		//starting from the 3rd row from where the client area begins
	{
		for (int j = 1; j < col - 1; j++){	//starting from the 1st column from where the client area begins
			if (i == r + 3 && j == c + 1)
				clientarea[i][j] = ch;
		}
	}
}
char FramedCanvas::getCharacter(int c, int r) const
{
	int row = geth() + 4;
	int col = getw() + 2;

	for (int i = 3; i < row - 1; i++)		//starting from the 3rd row from where the client area begins
	{
		for (int j = 1; j < col - 1; j++){	//starting from the 1st column from where the client area begins
			if (i == r + 3 && j == c + 1)
			{
				return clientarea[i][j];
				break;
			}
		}
	}
	return ' ';
}

FramedCanvas::~FramedCanvas()
{
	//cout << "Framed Canvas" << endl;
}