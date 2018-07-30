#pragma once
#include "Border.h"


class LineBorder :public Border
{
public:
	LineBorder();
	void drawBorder(Graphics& g, short left, short top, int width , int height);

	~LineBorder();
};

