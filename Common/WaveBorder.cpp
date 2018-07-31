#include "WaveBorder.h"
#include <iostream>

using namespace std;
WaveBorder::WaveBorder()
{
}

void WaveBorder::drawBorder(Graphics & g, short left, short top, int width, int height)
{
	short topBorder = top;
	short leftBorder = left;

	g.moveTo(leftBorder, topBorder);

	cout << '\x7E';
	for (int i = 0; i < width - 2; i++) {
		cout << '\x7E';
	}
	cout << '\x7E';									//top right corner
	g.moveTo(leftBorder, topBorder + 1);
	int tempX = topBorder + 1;
	for (int i = 0; i < height - 2; i++) {
		cout << '\x7E';										//left
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\x7E';										//right
		g.moveTo(leftBorder, tempX++);
	}
	g.moveTo(leftBorder, topBorder + height - 2);
	cout << '\x7E';						//right buttom corner
	g.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << '\x7E';					//buttom line
	}
	cout << '\x7E';						//right buttom corner


	
}

WaveBorder::~WaveBorder()
{
}
