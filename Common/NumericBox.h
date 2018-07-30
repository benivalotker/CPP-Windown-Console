#pragma once
#include "../Common/Control.h"
#include "Button.h"

class NumericBox : public Control {

private:
	int max, min;
	int value;
	int width;
public:

	NumericBox(Border* border, short _left, short _top);
	void draw(Graphics& g, int x, int y, size_t z);

	void mousePressed(int x, int y, bool isLeft);	
	int getWidth() { return width; };
	~NumericBox();
};