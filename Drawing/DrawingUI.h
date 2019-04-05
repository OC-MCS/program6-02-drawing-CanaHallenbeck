
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

//----------------------------------------------------
//	Drawing UI -- 
//	Responsible for user interface; drawing 
//	shapes on screen; tells shapeMgr location of shapes
//----------------------------------------------------

class DrawingUI
{
private:
	RectangleShape canvas;
public:
	DrawingUI(Vector2f p);
	void draw(RenderWindow& win, ShapeMgr *mgr);
	bool isMouseInCanvas(Vector2f mousePos);

};

