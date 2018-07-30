#pragma once
#include "../Common/Label.h"


class Button : public Control {

private:
	string value;
	int width;
	int height;
	bool clicked;

public:
	Button(Border* _border, short _left, short _top, string val);
	void draw(Graphics& g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	bool canGetFocus() { return TRUE; };
	int getWidth();
	~Button();

};