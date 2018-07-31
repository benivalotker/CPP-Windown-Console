#include "RadioList.h"



//Constructor
RadioList::RadioList(Border * _border, short _left, short _top, vector<string> _values) :Control(_left, _top, _border), currentCboxIndex(-1), selectedIndex(0) , lastSelected(-1)
{
	for (int i = 0; i < _values.size(); i++) {
		radioBoxs.push_back(new RadioBox(_left + 2, 1 + (i * 3), _values[i]));
		COORD pos = { _left + (short)4  , _top + (short)(2 + (i * 3)) };
		checkBoxCoord.push_back(pos);
	}
}

//overloads father method
void RadioList::draw(Graphics & g, int x, int y, size_t z)
{
	g.setBackground(bgColor);
	g.setForeground(fgColor);
	border->drawBorder(g, x, y, 25, static_cast<int>(radioBoxs.size() * 4));
	for (auto c : radioBoxs) {
		c->draw(g, c->getLeft(), y + c->getTop(), z);
	}
}

//reacts on press mouse
void RadioList::mousePressed(int x, int y, bool isLeft)
{

}

//reacts on key down
void RadioList::keyDown(int keyCode, char charecter, Graphics & g)
{
	int vectorSize = static_cast<int>(radioBoxs.size());
	
	switch (keyCode)
	{

		//tab pressed
	case VK_TAB:
		// if no focused
		if (++currentCboxIndex == 0)
		{
			selectedIndex = currentCboxIndex;
			radioBoxs[currentCboxIndex]->flipBgToWhite();
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize - 1)
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//key down pressed
	case VK_DOWN:
		// if no focused
		if (++currentCboxIndex == 1)
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex == 0)
		{
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize)
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[0]->flipBgToWhite();
			currentCboxIndex = 0;
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//numpad 2 was pressed like key up
	case VK_NUMPAD2:
		// if no focused
		if (++currentCboxIndex == 1)
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex == 0)
		{
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		else if (currentCboxIndex == vectorSize)
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[0]->flipBgToWhite();
			currentCboxIndex = 0;
			selectedIndex = currentCboxIndex;
		}
		// middle
		else
		{
			radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		break;

		//key up was pressed
	case VK_UP:
		// if no focused
		if (--currentCboxIndex == 0)
		{
			radioBoxs[currentCboxIndex + 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex <= -1)
		{
			currentCboxIndex = vectorSize - 1;
			radioBoxs[0]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		// middle
		else
		{
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			radioBoxs[currentCboxIndex + 1]->flipBgToBlack();
			selectedIndex = currentCboxIndex;
		}
		break;

		//numpad8 pressed like key up
	case VK_NUMPAD8:
		// if no focused
		if (--currentCboxIndex == 0)
		{
			radioBoxs[currentCboxIndex + 1]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		else if (currentCboxIndex <= -1)
		{
			currentCboxIndex = vectorSize - 1;
			radioBoxs[0]->flipBgToBlack();
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			selectedIndex = currentCboxIndex;
		}
		// if is in last position befor out of the check list
		// middle
		else
		{
			radioBoxs[currentCboxIndex]->flipBgToWhite();
			radioBoxs[currentCboxIndex + 1]->flipBgToBlack();
			selectedIndex = currentCboxIndex;
		}
		break;

		//space was pressed to select current item and check it
	case VK_SPACE:
		if (lastSelected == -1)
		{
			lastSelected = selectedIndex;
			radioBoxs[selectedIndex]->setIsSelected();
		}
		else
		{
			radioBoxs[lastSelected]->setIsSelected();
			radioBoxs[selectedIndex]->setIsSelected();
			lastSelected = selectedIndex;
		}
	
		break;

	}
}

//return true if selected
bool RadioList::getIsInLastChild()
{
	int vectorSize = static_cast<int>(radioBoxs.size());
	// if no focused
	if (++currentCboxIndex == 0)
	{
		selectedIndex = currentCboxIndex;
		radioBoxs[currentCboxIndex]->flipBgToWhite();
		return FALSE;
	}
	// if is in last position befor out of the check list
	else if (currentCboxIndex == vectorSize - 1)
	{
		radioBoxs[currentCboxIndex]->flipBgToWhite();
		radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
		currentCboxIndex = vectorSize - 1;
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
	else if (currentCboxIndex == vectorSize)
	{
		radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
		currentCboxIndex = -1;
		return TRUE;
	}
	// middle
	else
	{
		radioBoxs[currentCboxIndex - 1]->flipBgToBlack();
		radioBoxs[currentCboxIndex]->flipBgToWhite();
		selectedIndex = currentCboxIndex;
		return FALSE;
	}
}

//set focus
void RadioList::onFocus(bool flag)
{
	focus = flag;
}



//Destructor

RadioList::~RadioList()
{
}
