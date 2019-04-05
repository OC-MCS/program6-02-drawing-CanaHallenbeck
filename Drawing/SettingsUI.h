#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

//-----------------------------------------------------
//	Settings UI -- user interface for settings (button
//	clicks, draws button options)
//----------------------------------------------------

class SettingsUI
{
private:
	CircleShape blueBtn, // <--------------------------- Blue button on user interface
				redBtn,	  // <--------------------------- Red button on user interface       
				greenBtn,   // <----------------------- Green button on user interface
				yellowBtn, // <----------------------- Yellow button on user interface
				cyanBtn,   // <------------------------- Cyan button on user interface
				magentaBtn, // <--------------------- Magenta button on user interface

				   circleBtn;  //   <-------------------------- Circle (shape) button on user interface
	RectangleShape squareBtn; //   <--------------------------- Sqaure (shape) button on user interface

public:
	SettingsUI(SettingsMgr *mgr);
	
	void handleMouseUp(Vector2f mouse, SettingsMgr *mgr);
	void draw(RenderWindow& win, SettingsMgr *mgr);

};
