#pragma once
#include "Graphics.h"


class Border
{
public:
	Border();
	virtual void drawBorder(Graphics& g , short left, short top, int width , int height) {};
	virtual ~Border();
};

