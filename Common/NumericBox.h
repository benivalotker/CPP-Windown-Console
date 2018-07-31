#pragma once
#include "../Common/Control.h"
#include "Button.h"

class NumericBox : public Control {

private:
	int max, min;
	int value;
	int width;
	bool focus;

public:

	NumericBox(Border* border, short _left, short _top);
	void draw(Graphics& g, int x, int y, size_t z);
	void keyDown(int keyCode, char charecter, Graphics & g);
	void mousePressed(int x, int y, bool isLeft);
	void onFocus(bool flag);
	bool canGetFocus() { return TRUE; };
	int getWidth() { return width; };
	~NumericBox();
};