#include "../Common/Graphics.h"
#include "../Common/EventEngine.h"
#include "../Common/Label.h"
#include "../Common/CheckList.h"
#include "../Common/Panel.h"
#include "../Common/Button.h"
#include "../Common/NumericBox.h"
#include "../Common/TextBox.h"
#include "../Common/RadioList.h"
#include "../Common/MassageBox.h"
#include "../Common/ComboBox.h"
#include <iostream>

using namespace std;




int main(int argc, char** argv)
{
	EventEngine e;

	//CheckBox cb(2, 2, "ssdf");
	CheckList cl(new LineBorder() , 2, 2, { "check Box 1" , "check Box 2"  , "check Box 3" ,  "check Box 4" });
	CheckList cl2(new LineBorder(), 40, 2, { "check Box 1" , "check Box 2"  , "check Box 3" ,  "check Box 4" });

	//radio list
	RadioList rb(new LineBorder(), 75, 2, { "Radio  Box 1" , "Radio  Box 2"  , "Radio  Box 3" ,  "Radio  Box 4" });

	//comboBox
	ComboBox cob(new LineBorder(), 50, 17, { "Combobox 1" , "Combobox 2"  , "Combobox 3" ,  "Combobox 4" });

	//panel
	Panel p(new LineBorder(), 1, 1);

	p.setWidth(100);
	p.setHeight(30);

	//NumericBox
	NumericBox nb1(new LineBorder(), 2, 17);
	NumericBox nb2(new LineBorder(), 23, 17);

	//TextBox
	TextBox textBox(new LineBorder(), 2, 20, 20, 4);
	TextBox textBox1(new LineBorder(), 23, 20, 20, 4);

	//massageBox
	MassageBox mb(37, 8, "Massage Box");
	
	//button
	Button b(new LineBorder(), 2, 23, "button");
	Button b2(new LineBorder(), 23, 23, "Submit");

	//button event
	b2.setEvent(&mb);
	
	p.addControlsToVector(&cl);
	p.addControlsToVector(&cl2);
	p.addControlsToVector(&rb);
	p.addControlsToVector(&textBox);
	p.addControlsToVector(&nb1);
	p.addControlsToVector(&nb2);
	p.addControlsToVector(&textBox1);
	p.addControlsToVector(&b);
	p.addControlsToVector(&b2);
	p.addControlsToVector(&mb);
	p.addControlsToVector(&cob);


	Control* firstFocus;
	if (firstFocus = p.getFirstControl())
	{
		Control::setFocus(*firstFocus);
	}
	
	e.run(p);
	
	

}