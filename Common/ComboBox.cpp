#include "ComboBox.h"

ComboBox::ComboBox() {};

ComboBox::ComboBox(Border *_border, short _left, short _top, int _width, int _height, vector < string > val)
	:Control(_left, _top, _border), width(_width), height(_height), cursor(0), focus(FALSE), values(val)
{};

ComboBox::~ComboBox() {};


void ComboBox::onFocus(bool flag)
{
	focus = flag;
}

void ComboBox::draw(Graphics & g, int x, int y, size_t z)
{
	y = y + 1;
	this->border->drawBorder(g, x, y-1, this->width, this->height);
	for (int i = 0; i < values.size(); i++) {
		g.setBackground(bgColor);
		g.setForeground(fgColor);
		g.moveTo(x + 4, y + i*2);
		g.write(values[i]);
	}
}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	OutputDebugString("ddfdf");
}