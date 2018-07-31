#pragma once
#include "Control.h"
#include "../Common/Border.h"
#include <iostream>


class ComboBox : public Control
{
public:
	ComboBox();
	ComboBox(Border *_border, short _left, short _top, int _width, int _height, vector < string > val);
	~ComboBox();
	void onFocus(bool flag);
	bool canGetFocus() { return TRUE; };
	void draw(Graphics& g, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter, Graphics & g) {};
	void mousePressed(int x, int y, bool isLeft);
	int getWidth() { return width; };

private:
	vector < string > values;
	int width;
	int height;
	int cursor;
	bool focus;
	bool isSelected;
};