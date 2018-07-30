#pragma once
#include "Control.h"
class RadioBox : public Control
{
private:
	string value;
	bool isSelected;

public:
	RadioBox(short _left, short _top, string _value);
	void draw(Graphics& g, int x, int y, size_t z);
	void mousePressed(int x, int y, bool isLeft);
	void keyDown(int keyCode, char charecter) {};
	bool canGetFocus() { return TRUE; };
	bool isListObj() { return TRUE; };
	void flipBgToWhite();
	void flipBgToBlack();
	bool getIsSelected();
	void setIsSelected();
	~RadioBox();
};

