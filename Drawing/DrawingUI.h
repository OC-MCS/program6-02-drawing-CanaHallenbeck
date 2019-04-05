
#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"


class DrawingUI
{
private:
	RectangleShape canvas;
public:
	DrawingUI(Vector2f p)
	{

		canvas.setPosition(p);			         
		canvas.setOutlineColor(Color::White);	  
		canvas.setOutlineThickness(3);			
		canvas.setSize(Vector2f(610, 600));
		canvas.setFillColor(Color::Transparent); 		 
																			   
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		win.draw(canvas);

		for (int i = 0; mgr->getAmntFilled() > 0 && i < mgr->getAmntFilled(); i++)
		{
			mgr->getList(i)->draw(win);
		}
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		if (canvas.getGlobalBounds().contains(mousePos) && mousePos.x < 760 && mousePos.y < 590)
			return true;
		else
			return false;
	}

};

