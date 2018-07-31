#include "DoubleBorder.h"
#include <iostream>

using namespace std;
DoubleBorder::DoubleBorder()
{
}

void DoubleBorder::drawBorder(Graphics & g, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	g.moveTo(leftBorder, topBorder);

	cout << '\xC9';
	for (int i = 0; i < width - 2; i++) {
		cout << '\xCD';
	}
	cout << '\xBB';									//top right corner
	g.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\xBA';										//left
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\xBA';										//right
		g.moveTo(leftBorder, tempX++);
	}
	g.moveTo(leftBorder, topBorder + height - 2);
	cout << '\xC8';						//right buttom corner
	g.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << '\xCD';					//buttom line
	}
	cout << '\xBC';						//right buttom corner


	
}

DoubleBorder::~DoubleBorder()
{
}
