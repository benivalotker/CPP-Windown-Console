#pragma once
#include "Border.h"


class DotBorder :public Border
{
public:
	DotBorder();
	void drawBorder(Graphics& g, short left, short top, int width, int height);

	~DotBorder();
};

