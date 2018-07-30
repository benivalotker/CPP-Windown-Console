#pragma once
#include "Control.h"



class Label : public Control
{

private:
	string value;

public:
	Label(short _left ,short _top , string _value);


	void draw(Graphics& g, int x, int y, size_t z);
	//void mousePressed(int x, int y, bool isLeft);
	//void keyDown(int keyCode, char charecter);
	

	~Label();
};

