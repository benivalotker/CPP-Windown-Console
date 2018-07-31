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

	cout << '\xDA';
	for (int i = 0; i < width - 2; i++) {
		cout << '\xC4';
	}
	cout << '\xBF';
	g.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\xB1';
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\xB1';
		g.moveTo(leftBorder, tempX++);
	}
	g.moveTo(leftBorder, topBorder + height - 2);
	cout << '\xC0';
	g.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << '\xC4';
	}
	cout << '\xD9';
}

DoubleBorder::~DoubleBorder()
{
}
