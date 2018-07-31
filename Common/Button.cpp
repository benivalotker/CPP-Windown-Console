#include "Button.h"
#include "Control.h"

Button::Button(Border* _border, short _left, short _top, string _value) : Control(_left, _top, _border), value(_value), clicked(FALSE)
{
	width = static_cast<int>(_value.size() + 2);
}



void Button::draw(Graphics & g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->drawBorder(g, x, y,static_cast<int>(value.size()) + 2, 4);
	g.setCursorVisibility(FALSE);
	g.moveTo(x + 1, y + 1);
	g.write(value);
}

void Button::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugString("press");
	if (y == top && (x > left && x < (left + static_cast<int>(value.size()) - 1)))
	{
		if (!clicked)
		{
			this->flipBgToWhite();
			clicked = TRUE;
		}
		else
		{
			this->flipBgToBlack();
			clicked = FALSE;
		}
	}


	for (int i = 0; i < events.size(); i++) 
	{
		events[i]->buttonEvent();
	}
	
}

int Button::getWidth() 
{
	return width; 
};

void Button::setEvent(Control* c)
{
	events.push_back(c);
}

Button::~Button() {}