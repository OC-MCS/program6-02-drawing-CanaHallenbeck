#include "SettingsUI.h"
using namespace std;

void Die(string msg);
SettingsUI::SettingsUI(SettingsMgr * mgr)
{
	// ?
}
void SettingsUI::handleMouseUp(Vector2f mouse, SettingsMgr * mgr)
{
	if (blueBtn.getGlobalBounds().contains(mouse))
	{
		cout << "BLUE" << endl; // button register test
		mgr->setCurColor(Color::Blue);
	}
	else if (redBtn.getGlobalBounds().contains(mouse))
	{
		cout << "RED" << endl;
		mgr->setCurColor(Color::Red);
	}
	else if (greenBtn.getGlobalBounds().contains(mouse))
	{
		cout << "GREEN" << endl;
		mgr->setCurColor(Color::Green);
	}
	else if (yellowBtn.getGlobalBounds().contains(mouse))
	{
		cout << "YELLOW" << endl;
		mgr->setCurColor(Color::Yellow);
	}
	else if (cyanBtn.getGlobalBounds().contains(mouse))
	{
		cout << "CYAN" << endl;
		mgr->setCurColor(Color::Cyan);
	}
	else if (magentaBtn.getGlobalBounds().contains(mouse))
	{
		cout << "MAGENTA" << endl;
		mgr->setCurColor(Color::Magenta);
	}
	else if (circleBtn.getGlobalBounds().contains(mouse))
	{
		cout << "****CIRCLE****" << endl;
		mgr->setCurShape(CIRCLE);
	}
	else if (squareBtn.getGlobalBounds().contains(mouse))
	{
		cout << "****SQUARE****" << endl;
		mgr->setCurShape(SQUARE);
	}
}
void SettingsUI::draw(RenderWindow & win, SettingsMgr * mgr)
{

	
	//---------------------------------------------------------------------,
	//			 		     TEXT (DRAWN STRINGS) 						   |
	//---------------------------------------------------------------------|
	//																	   |
	//		,------"Color"												   |
	//      |															   |
	//		v													---		   |
	   Font colorFont;											  //       |
	if (!colorFont.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) //	   |
		Die("couldn't load font");								  //	   |
																  // 	   |													   
	   Text color("Color", colorFont, 25);						  //       |
	   color.setPosition(52, 30);								  //	   |
	//															---		   |	
	//																	   |
	//		,------"Shape"												   |
	//      |															   |
	//		v													---		   |
	   Font shapeFont;											  //       |
	if (!shapeFont.loadFromFile("C:\\Windows\\Fonts\\arial.ttf")) //       |
		Die("couldn't load font");								  //	   |													 
																  //	   |
	    Text shape("Shape", shapeFont, 25);						  //	   |
	    shape.setPosition(45, 430);								  //	   |
	//															---		   |
	//		----------------------------------------------------------	   |
	//				        DRAW TEXT ON SCREEN						       |
    //		----------------------------------------------------------	   |	
	//																	   |
		win.draw(color);					//							   |
		win.draw(shape);                    //			    			   |														 
	//											    					   |
	//																	   |
	//																	   |
	//															 		   |
	//---------------------------------------------------------------------'

	//----------------------------------------------------------,
	//			 		  COLOR  BUTTONS						|
	//----------------------------------------------------------|
	//															|
	//		,------Blue Button									|
	//      |													|
	//		v								----				|
	  Vector2f bbPos(60, 75);					//				|
	  blueBtn.setPosition(bbPos);               //				|
	  blueBtn.setRadius(20);					//				|
	  blueBtn.setOutlineThickness(2);           //				|
	  blueBtn.setOutlineColor(Color::Blue);     //				|
	//										----				|
	//															|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//															|
	//												  ----		|
	   if (mgr->getCurColor() == Color::Blue)			 //		|
	   blueBtn.setFillColor(Color::Blue);			     //		|
	   else											     //		|
	   blueBtn.setFillColor(Color::Transparent);         //		|
    //												  ----		|
	//															|
	//		,--------Red Button									|
	//      |  													|
	//		v								  ----				|
	  Vector2f rbPos(60, 135);				     //				|
	  redBtn.setPosition(rbPos);				 //				|
	  redBtn.setRadius(20);					     //				|
	  redBtn.setOutlineThickness(2);             //				|
	  redBtn.setOutlineColor(Color::Red);        //				|
	//										  ----				|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//												  ----		|
	  if (mgr->getCurColor() == Color::Red)				 //		|
		redBtn.setFillColor(Color::Red);			     //		|
	  else											     //		|
		redBtn.setFillColor(Color::Transparent);         //		|
	//												  ----		|
	//		,--------Green Button								|	
	//      |													|
	//		v				               -----				|
	  Vector2f gbPos(60, 190);			         //				|
	  greenBtn.setPosition(gbPos);               //				|
	  greenBtn.setRadius(20);					 //				|
	  greenBtn.setOutlineThickness(2);           //				|
	  greenBtn.setOutlineColor(Color::Green);    //				|
	//									   -----				|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//												 -----		|
	   if (mgr->getCurColor() == Color::Green)			 //		|
	   greenBtn.setFillColor(Color::Green);			     //		|
      else											     //		|
	   greenBtn.setFillColor(Color::Transparent);        //		|
	//												 -----		|
	//		,--------Yellow Button								|
	//		|													|
	//		v								 -----				|
	   Vector2f ybPos(60, 250);					 //				|
	   yellowBtn.setPosition(ybPos);		     //				|
	   yellowBtn.setRadius(20);				     //				|
	   yellowBtn.setOutlineThickness(2);         //				|
	   yellowBtn.setOutlineColor(Color::Yellow); //				|
	//										 -----				|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//															|
	if (mgr->getCurColor() == Color::Yellow)			   //	|
		yellowBtn.setFillColor(Color::Yellow);			   //	|
    else											       //	|
	   yellowBtn.setFillColor(Color::Transparent);         //	|
	//															|
	//															|
	//		,--------Cyan Button								|
	//		|													|
	//		v													|
	   Vector2f cbPos(60, 310);				       //			|
	   cyanBtn.setPosition(cbPos);				   //			|
	   cyanBtn.setRadius(20);					   //			|	
	   cyanBtn.setOutlineThickness(2);			   //			|
	   cyanBtn.setOutlineColor(Color::Cyan);       //			|
	//															|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//															|
	  if (mgr->getCurColor() == Color::Cyan)			 //		|
		cyanBtn.setFillColor(Color::Cyan);			     //		|
	 else											     //		|
		cyanBtn.setFillColor(Color::Transparent);        //		|
	//															|
	//		,--------Magenta Button								|
	//		|													|
	//		v													|
	   Vector2f mPos(60, 370);						 //			|
	   magentaBtn.setPosition(mPos);				 //			|
	   magentaBtn.setRadius(20);					 //			|
	   magentaBtn.setOutlineThickness(2);			 //			|
	   magentaBtn.setOutlineColor(Color::Magenta);   //		    |
	//															|
	//		---------------------------------------------	    |
	//				   BUTTON FILL CHECK						|
	//		---------------------------------------------	    |
	//															|
	if (mgr->getCurColor() == Color::Magenta)				//	|
	magentaBtn.setFillColor(Color::Magenta);	            //  |
    else											        //  |
	magentaBtn.setFillColor(Color::Transparent);            //  |
	//															|
	//		,--------Draw all Color Buttons						|
	//		|													|
	//		v													|
	win.draw(blueBtn);    //									|
	win.draw(redBtn);     //									|
	win.draw(greenBtn);   //									|
	win.draw(yellowBtn);  //									|
	win.draw(cyanBtn);    //									|
	win.draw(magentaBtn); //									|
	//															|
	//----------------------------------------------------------'


	//---------------------------------------------------,
	//			 	  SHAPE  BUTTONS					 |
	//---------------------------------------------------|
	//													 |
	//		,------Circle Button						 |
	//      |											 |
	//		v											 |
	Vector2f cirPos(65, 478);					 //		 |
	circleBtn.setPosition(cirPos);				 //		 |
	circleBtn.setRadius(15);                     //		 |
	circleBtn.setOutlineColor(Color::White);     //		 |
	circleBtn.setOutlineThickness(2);			 //		 |
	circleBtn.setFillColor(Color::Transparent);  //		 |
	//													 |
	//													 |
	// ---------------------------------------------	 |
	//			   BUTTON FILL CHECK					 |
	// ---------------------------------------------	 |
	//												     |
	//										    ----	 |
	if (mgr->getCurShape() == CIRCLE)			    //	 |
		circleBtn.setFillColor(Color::White);	    //	 |
	else										    //	 |
		circleBtn.setFillColor(Color::Transparent); //	 |
	//										    ----	 |
	//		,------Square Button						 |
	//      |											 |
	//		v											 |
	Vector2f sqPos(67, 535);					 //		 |
	squareBtn.setPosition(sqPos);				 //		 |
	squareBtn.setOutlineColor(Color::White);     //		 |
	squareBtn.setOutlineThickness(2);			 //		 |
	squareBtn.setSize(Vector2f(25, 25));		 //		 |
	squareBtn.setFillColor(Color::Transparent);  //		 |
	//													 |
	// ---------------------------------------------	 |
	//			   BUTTON FILL CHECK					 |
	// ---------------------------------------------	 |
	//												     |
	//										    ----	 |
	if (mgr->getCurShape() == SQUARE)			    //	 |
		squareBtn.setFillColor(Color::White);	    //	 |
	else										    //	 |
		squareBtn.setFillColor(Color::Transparent); //	 |
	//										    ----	 |
	//		,------Draw									 |
	//      |											 |
	//		v											 |
	win.draw(squareBtn); //								 |
	win.draw(circleBtn); //								 |
	//													 |
	//---------------------------------------------------'


}

void Die(string msg)
{
	cout << msg << endl;
	exit (-1);
}
