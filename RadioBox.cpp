#include "RadioBox.h"
#include <iostream>

using namespace std;


//Constructor
RadioBox::RadioBox(short _left, short _top, string _value) :Control(_left, _top) , value(_value), isSelected(FALSE)
{
}

//Draw function overloading from father
void RadioBox::draw(Graphics & g, int x, int y, size_t z)
{
	g.moveTo(x, y);
	g.setBackground(bgColor);
	g.setForeground(fgColor);


	cout << '\xDA' << '\xC4' << '\xC4' << '\xBF';
	for (int i = 0; i < value.size() + 1; i++) {
		cout << ' ';
	}

	g.moveTo(x, y + 1);
	cout << '\xB3' << ' ' << ' ' << '\xB3' << ' ';

	g.moveTo(x, y + 2);
	cout << '\xC0' << '\xC4' << '\xC4' << '\xD9';

	for (int i = 0; i < value.size() + 1; i++) {
		cout << ' ';
	}

	if (isSelected)
	{
		g.write(x + 1, y + 1, "X");
	}

	g.moveTo(x + 5, y + 1);
	g.write(value);
}

//reaction on mouse press
void RadioBox::mousePressed(int x, int y, bool isLeft)
{
}

//colors the current item to white
void RadioBox::flipBgToWhite()
{
	bgColor = Color::White;
	fgColor = Color::Black;
}

//colors the current item to black
void RadioBox::flipBgToBlack()
{
	bgColor = Color::Black;
	fgColor = Color::White;
}

//returns true if the current item is selected
bool RadioBox::getIsSelected()
{
	return isSelected;
}

//set the current item as selected item
void RadioBox::setIsSelected()
{
	if (!isSelected)
	{
		isSelected = TRUE;
	}
	else
	{
		isSelected = FALSE;
	}
}

//Destructor
RadioBox::~RadioBox()
{
}
