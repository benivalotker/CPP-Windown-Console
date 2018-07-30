#include "Label.h"



Label::Label(short _left, short _top , string _value) :Control(_left , _top) , value(_value)
{
}

void Label::draw(Graphics & g, int x, int y, size_t z)
{
	g.moveTo(x, y);
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	
	
	g.moveTo(x + 3, y + 1);
	g.write(value);
}

Label::~Label()
{
}
