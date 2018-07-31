#include "CheckList.h"
#include <iostream>
using namespace std;


//Constructor
CheckList::CheckList(Border * _border, short _left, short _top, vector<string> _values) :Control(_left, _top, _border), currentCboxIndex(-1) , selectedIndex(0)
{
	for (int i = 0; i < _values.size(); i++) {
		checkBoxs.push_back(new CheckBox(_left + 2, 1 + (i * 3), _values[i]));
		COORD pos = { _left + (short)4  , _top + (short)(2 + (i * 3)) };
		checkBoxCoord.push_back(pos);
	}
}

//Draw finction overloading from father
void CheckList::draw(Graphics & g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->drawBorder(g , x, y, 25, static_cast<int>(checkBoxs.size() * 4));
	for (auto c : checkBoxs) {
		c->draw(g,  c->getLeft()  , y  + c->getTop(), z);
	}
}

//reaction on mouse press
void CheckList::mousePressed(int x, int y, bool isLeft)
{
}


//reaction on key down
void CheckList::keyDown(int keyCode, char charecter , Graphics & g)
{
	int vectorSize = static_cast<int>(checkBoxs.size());
	
	switch (keyCode)
	{
		//Tab button pressed
		case VK_TAB:
			// if no focused
			if (++currentCboxIndex == 0)
			{
				selectedIndex = currentCboxIndex;
				checkBoxs[currentCboxIndex]->flipBgToWhite();
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize -1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}	
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//Key down pressed
		case VK_DOWN:
			// if no focused
			if (++currentCboxIndex == 1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[0]->flipBgToWhite();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//num pad 2 pressed
		case VK_NUMPAD2:
			// if no focused
			if (++currentCboxIndex == 1)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			else if (currentCboxIndex == vectorSize)
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[0]->flipBgToWhite();
				currentCboxIndex = 0;
				selectedIndex = currentCboxIndex;
			}
			// middle
			else
			{
				checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			break;

			//key up button pressed
		case VK_UP:
			// if no focused
			if (--currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				checkBoxs[0]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			// middle
			else
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();	
				selectedIndex = currentCboxIndex;
			}
			break;

			//numpad 8 pressed like up
		case VK_NUMPAD8:
			// if no focused
			if (--currentCboxIndex == 0)
			{
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			else if (currentCboxIndex <= -1)
			{
				currentCboxIndex = vectorSize - 1;
				checkBoxs[0]->flipBgToBlack();
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				selectedIndex = currentCboxIndex;
			}
			// if is in last position befor out of the check list
			// middle
			else
			{
				checkBoxs[currentCboxIndex]->flipBgToWhite();
				checkBoxs[currentCboxIndex + 1]->flipBgToBlack();
				selectedIndex = currentCboxIndex;
			}
			break;

			//Space button pressed to selected to check the current item
		case VK_SPACE:

			checkBoxs[selectedIndex]->setIsSelected();
			break;

	}
}

//returns true if the focus is on the last child item of the cheklist
bool CheckList::getIsInLastChild()
{	
	int vectorSize = static_cast<int>(checkBoxs.size());
	// if no focused
	if (++currentCboxIndex == 0)
	{
		selectedIndex = currentCboxIndex;
		checkBoxs[currentCboxIndex]->flipBgToWhite();
		return FALSE;
	}
	// if is in last position befor out of the check list
	else if (currentCboxIndex == vectorSize - 1)
	{
		checkBoxs[currentCboxIndex]->flipBgToWhite();
		checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
		currentCboxIndex = vectorSize - 1;
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize )
	{
		checkBoxs[vectorSize - 1]->flipBgToBlack();
		currentCboxIndex = - 1;
		return TRUE;
	}
	// middle
	else
	{
		checkBoxs[currentCboxIndex - 1]->flipBgToBlack();
		checkBoxs[currentCboxIndex]->flipBgToWhite();
		selectedIndex = currentCboxIndex;
		return FALSE;
	}

}

//if focused, turn up the flag
void CheckList::onFocus(bool flag)
{
	focus = flag;
}


//Destructor
CheckList::~CheckList()
{
}
