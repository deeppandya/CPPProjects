#ifndef CANVAS_H
#define CANVAS_H

#include<string>
#include<vector>
using namespace std;

class Canvas
{
private:
	int height, width;

public:
	vector<vector<char>> clientarea;
	Canvas(int w, int h);
	int geth() const;
	int getw() const;
	virtual void clearClientArea(char ch = _BLANK);
	virtual void putCharacter(int c, int r, char ch = '*');
	virtual char getCharacter(int c, int r) const;
	virtual void decorateClientArea();
	virtual ~Canvas();

	friend ostream& operator<<(ostream& out, Canvas& can);
};

#endif


