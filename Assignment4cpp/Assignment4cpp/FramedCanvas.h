#ifndef FRAMEDCANVAS_H
#define FRAMEDCANVAS_H
#include"Canvas.h"

class FramedCanvas :public Canvas
{
	string title;
public:
	FramedCanvas(int w, int h, string title = "A Framed Canvas");
	virtual void decorateClientArea();
	virtual void clearClientArea(char ch = ' ');
	virtual void putCharacter(int c, int r, char ch = '*');
	virtual char getCharacter(int c, int r) const;
	virtual ~FramedCanvas();
};

#endif