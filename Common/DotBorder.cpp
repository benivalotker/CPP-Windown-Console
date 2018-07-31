#include "DoubleBorder.h"
#include <iostream>

using namespace std;
DotBorder::DotBorder()
{
}

void DotBorder::drawBorder(Graphics & g, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	g.moveTo(leftBorder, topBorder);

	cout << '\xF9';
	for (int i = 0; i < width - 2; i++) {
		cout << '\xF9';
	}
	cout << '\xF9';									//top right corner
	g.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\xF9';										//left
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\xF9';										//right
		g.moveTo(leftBorder, tempX++);
	}
	g.moveTo(leftBorder, topBorder + height - 2);
	cout << '\xF9';						//right buttom corner
	g.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << '\xF9';					//buttom line
	}
	cout << '\xF9';						//right buttom corner


	
}

DotBorder::~DotBorder()
{
}
