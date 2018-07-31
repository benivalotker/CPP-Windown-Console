#include "ComboBox.h"
#include <iostream>

using namespace std;


ComboBox::ComboBox(Border* _border, short _left, short _top, vector<string> _values) :Control(_left, _top, _border), values(_values), width(20), isOpen(FALSE), currentIndex(0)
{
	valueToDisplay = _values[0];
}


void ComboBox::draw(Graphics & g, int x, int y, size_t z)
{
	int vectorSize = static_cast<int>(values.size());
	g.moveTo(x, y);
	g.setBackground(bgColor);
	g.setForeground(fgColor);

	if (!isOpen)
	{
		cout << '\xDA';
		for (int i = 0; i < 18; i++)
		{
			cout << '\xC4';
		}
		cout << '\xBF';
		g.moveTo(x, y + 1);
		cout << '\xB3';
		for (int i = 0; i < 16; i++)
		{
			cout << ' ';
		}
		cout << '\xB3' << '\xF0' << '\xB3';
		g.write(x + 2, y + 1, valueToDisplay);
		g.moveTo(x, y + 2);
		cout << '\xC0';
		for (int i = 0; i < 18; i++)
		{
			cout << '\xC4';
		}
		cout << '\xD9';
	}
	else
	{
		cout << '\xDA';
		for (int i = 0; i < 18; i++)
		{
			cout << '\xC4';
		}
		cout << '\xBF';
		g.moveTo(x, y + 1);
		cout << '\xB3';
		for (int i = 0; i < 16; i++)
		{
			cout << ' ';
		}
		cout << '\xB3' << '\xF0' << '\xB3';
		g.write(x + 2, y + 1, values[0]);
		g.moveTo(x, y + 2);
		cout << '\xB3';
		for (int i = 0; i < 18; i++)
		{
			cout << '\xC4';
		}
		cout << '\xB3';


		int tempX = x;
		int tempY = y + 3;

		for (int y = 0; y < vectorSize; y++)
		{
			g.setBackground(bgColor);
			g.setForeground(fgColor);
			if (y == currentIndex)
			{
				g.setBackground(Color::White);
				g.setForeground(Color::Black);
			}
			if (y == vectorSize - 1)
			{
				g.moveTo(tempX, tempY);
				cout << '\xB3';
				for (int x = 0; x < 18; x++)
				{
					cout << ' ';
				}
				cout << '\xB3';
				g.write(tempX + 2, tempY, values[y]);
				g.moveTo(tempX, ++tempY);
				cout << '\xC0';
				for (int x = 0; x < 18; x++)
				{
					cout << '\xC4';
				}
				cout << '\xD9';
			}
			else
			{
				g.moveTo(tempX, tempY);
				cout << '\xB3';
				for (int x = 0; x < 18; x++)
				{
					cout << ' ';
				}
				cout << '\xB3';
				g.write(tempX + 2, tempY, values[y]);
				g.moveTo(tempX, ++tempY);
				cout << '\xB3';
				for (int x = 0; x < 18; x++)
				{
					cout << '\xC4';
				}
				cout << '\xB3';
				tempY++;
			}

		}
	}

}

void ComboBox::mousePressed(int x, int y, bool isLeft)
{
	if (y == top && (x > left && x < (left + width - 1)))
	{
		if (!isOpen)
		{
			isOpen = !isOpen;
			currentIndex = 0;
		}
		else
		{
			isOpen = !isOpen;
			currentIndex = 0;
		}
	}
}

void ComboBox::keyDown(int keyCode, char charecter, Graphics & g)
{
	int vectorSize = values.size();
	switch (keyCode)
	{
	case VK_TAB:

		break;
	case VK_DOWN:
		if(currentIndex == vectorSize -1)
		{
			currentIndex = 0;
		}
		else
		{
			currentIndex++;
		}
		break;
	case VK_NUMPAD2:
		if (currentIndex == vectorSize - 1)
		{
			currentIndex = 0;
		}
		else
		{
			currentIndex++;
		}
		break;
	case VK_UP:
		if (currentIndex == 0)
		{
			currentIndex = vectorSize - 1;
		}
		else
		{
			currentIndex--;
		}
		break;
	case VK_NUMPAD8:
		if (currentIndex == 0)
		{
			currentIndex = vectorSize - 1;
		}
		else
		{
			currentIndex--;
		}
		break;
	case VK_SPACE:
		valueToDisplay = values[currentIndex];
		isOpen = !isOpen;
		break;
	case VK_RETURN:
		valueToDisplay = values[currentIndex];
		isOpen = !isOpen;
		break;
	}
}

bool ComboBox::getIsInLastChild()
{
	int vectorSize = static_cast<int>(values.size());

	if (currentIndex == vectorSize)
	{
		currentIndex = 1;
		isOpen = !isOpen;
		return TRUE;
	}
	else
	{
		currentIndex++;
		return FALSE;
	}

}

void ComboBox::onFocus(bool flag)
{
}

ComboBox::~ComboBox()
{
}