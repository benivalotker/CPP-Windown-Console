#pragma once
#include "Panel.h"
#include "Label.h"
#include "Button.h"

class MassageBox : public Control
{
public:
	MassageBox(short _left, short _top, string labelString);

	void draw(Graphics& g, int x, int y, size_t z);
	bool canGetFocus() { return TRUE; };
	void onFocus(bool flag);
	void hide();
	void show();
	bool getVisible();
	void buttonEvent();

	~MassageBox();

private:
	Label l;
	Panel p;
	Button submit;
	Button cancel;
	bool isVisible = FALSE;
	bool focus;
};