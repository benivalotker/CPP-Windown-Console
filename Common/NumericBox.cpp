#include "NumericBox.h"
#include <iostream>

using namespace std;

NumericBox::NumericBox(Border * _border, short _left, short _top) : Control(_left, _top, _border) , value(0) , width(17), focus(FALSE)
{

}

void NumericBox::onFocus(bool flag)
{
	focus = flag;

}

void NumericBox::draw(Graphics& g, int x, int y, size_t z)
{
	short topBorder = top;
	short leftBorder = left;

	g.moveTo(leftBorder, topBorder);

	cout << '\xDA';
	for (int i = 0; i < 17 ; i++) {
		cout << '\xC4';
	}
	cout << '\xBF';

	g.moveTo(leftBorder, topBorder + 1);
	cout << '\xB3' << ' ' << "+" << ' ' << '\xB3';
	
	for (int i = 0; i < 9 ; i++) 
	{
			cout << ' ';
	}
	cout << '\xB3' << ' ' << "-" << ' ' << '\xB3';
	
	g.moveTo(leftBorder, topBorder + 2);
	cout << '\xC0';

	for (int i = 0; i < 17; i++) {
		cout << '\xC4';
	}
	cout << '\xD9';
	g.write(x + 6, y + 1, to_string(value));

	if (focus) {
		g.write("_");
	}
}

void NumericBox::mousePressed(int x, int y, bool isLeft)
{
	//if plus
	if (y == top && (x > left && x < left + 3))
	{
		value++;
	}
	//if minus
	else if(y == top && (x >= (left + 13) && x <= left + 16))
	{
		if (value == 0)
		{
			
		}
		else
		{
			--value;
		}
		
	}
}

void NumericBox::keyDown(int keyCode, char charecter, Graphics & g)
{
	switch (keyCode)
	{
	case VK_DELETE:
		value = 0;
		break;	
	case VK_LEFT:
		value++;
		break;
	case VK_NUMPAD4:
		value++;
	case VK_RIGHT:
		if (value == 0) {
			break;
		}
		value--;
		break;
	case VK_NUMPAD6:
		if (value == 0) {
			break;
		}
		value--;
		break;
	}
}

NumericBox::~NumericBox() {}