#include "LineBorder.h"
#include <iostream>

using namespace std;
LineBorder::LineBorder()
{
}

void LineBorder::drawBorder(Graphics & g, short left, short top, int width, int height)
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
		cout << '\xB3';
		for (int y = 0; y < width - 2; y++) {
			cout << ' ';
		}
		cout << '\xB3';
		g.moveTo(leftBorder, tempX++ );
	}
	g.moveTo(leftBorder, topBorder + height -2 );
	cout << '\xC0';
	g.moveTo(leftBorder + 1, topBorder + height - 2);
	for (int i = 0; i < width - 2; i++) {
		cout << '\xC4';
	}
	cout << '\xD9';
}

LineBorder::~LineBorder()
{
}
