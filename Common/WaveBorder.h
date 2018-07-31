#pragma once
#include "Border.h"


class WaveBorder :public Border
{
public:
	WaveBorder();
	void drawBorder(Graphics& g, short left, short top, int width, int height);

	~WaveBorder();
};

