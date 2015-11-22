#ifndef BORDEREDCANVAS_H
#define BORDEREDCANVAS_H
#include"Canvas.h"

class BorderedCanvas :public Canvas
{
public:
	BorderedCanvas(int w, int h);
	virtual void decorateClientArea();
	virtual void clearClientArea(char ch = ' ');
	virtual void putCharacter(int c, int r, char ch = '*');
	virtual char getCharacter(int c, int r) const;
	virtual ~BorderedCanvas();
};

#endif