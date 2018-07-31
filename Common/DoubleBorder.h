#pragma once
#include "Border.h"


class DoubleBorder :public Border
{
public:
	DoubleBorder();
	void drawBorder(Graphics& g, short left, short top, int width, int height);

	~DoubleBorder();
};

