//=======================================================
// Cana Hallenbeck
// Due Friday, March 29
// Programming II --  Programming Assignment 6
//
// Desc : A basic MS paint style program that allows
//		  the user to choose a color / shape and
//		  to close the window without losing their 
//		  drawing
//=======================================================

#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;

int main()
{

	const int WINDOW_WIDTH = 900;
	const int WINDOW_HEIGHT = 700;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	SettingsMgr settingsMgr(Color::Blue, ShapeEnum::CIRCLE);
	SettingsUI  settingsUI(&settingsMgr); 
	ShapeMgr    shapeMgr;
	DrawingUI   drawingUI(Vector2f(200, 50));

//===============================================================================================
	ifstream shapeDataListRead;
	shapeDataListRead.open("shapes.bin", ios::in | ios::binary);
	
	if (!shapeDataListRead)
	{
		cout << "file Open Failure" << endl;
		EXIT_FAILURE;
	}
	else
	{
		shapeMgr.readFile(shapeDataListRead, &settingsMgr);
	}

	shapeDataListRead.close();

	ofstream shapeDataListWrite;
	shapeDataListWrite.open("shapes.bin", ios::out | ios::binary);
	if (!shapeDataListWrite)
	{
		cout << "file Open Failure" << endl;
		EXIT_FAILURE;
	}
//==================================================================================================

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				shapeMgr.writeFile(shapeDataListWrite);
				shapeDataListWrite.close();
			}
			else if (event.type == Event::MouseButtonReleased) // Settings button check
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				settingsUI.handleMouseUp(mousePos, &settingsMgr);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left)) // Draw check
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				
				if (drawingUI.isMouseInCanvas(mousePos)) // In canvas and drawing ?
				{
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}

		window.clear();


		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window, &settingsMgr);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);


		window.display();
	} // end body of animation loop

	return 0;
}