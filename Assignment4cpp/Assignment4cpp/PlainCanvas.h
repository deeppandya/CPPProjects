#ifndef PLAINCANVAS_H
#define PLAINCANVAS_H
#include"Canvas.h"

class PlainCanvas :public Canvas
{
public:
	PlainCanvas(int w, int h);
	virtual void decorateClientArea();
	virtual void clearClientArea(char ch = ' ');
	virtual void putCharacter(int c, int r, char ch = '*');
	virtual char getCharacter(int c, int r) const;
	virtual ~PlainCanvas();
};

#endif