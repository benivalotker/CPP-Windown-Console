#include "MassageBox.h"

MassageBox::MassageBox(short _left, short _top, string labelString) :
	Control(_left, _top), l(left + 8, _top, labelString), p(new LineBorder(), _left, _top), submit(new LineBorder(), _left + 3, _top + 5, "Submit"), cancel(new LineBorder(), _left + 18, _top + 5, "Cancel"), focus(FALSE)
{
	p.setFocus(p);
	cancel.setEvent(this);
	submit.setEvent(this);
}

void MassageBox::onFocus(bool flag)
{
	focus = flag;
}

MassageBox::~MassageBox() {}

void MassageBox::hide()
{
	isVisible = false;
}

void MassageBox::show()
{
	isVisible = true;
}

bool MassageBox::getVisible()
{
	return isVisible;
}

void MassageBox::draw(Graphics& g, int x, int y, size_t z)
{
	p.setWidth(30);
	p.setHeight(10);
	p.addControlsToVector(&l);
	p.addControlsToVector(&submit);
	p.addControlsToVector(&cancel);

	if (isVisible) {
		p.draw(g, x, y, z);
	}
}


void MassageBox::buttonEvent() 
{
	if (isVisible == FALSE) 
	{
		isVisible = TRUE;
	}
	else
	{
		isVisible = FALSE;
	}
}