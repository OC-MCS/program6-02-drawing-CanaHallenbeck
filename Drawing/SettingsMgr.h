#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;
using namespace sf;

//-----------------------------------------------------
//	Settings Manager -- maintains current settings 
//  (current color, shape)
//----------------------------------------------------

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color shapeColor;
	ShapeEnum shapeShape;
public:

	SettingsMgr(Color startingColor, ShapeEnum startingShape);

	Color getCurColor() {return shapeColor;}
	ShapeEnum getCurShape() {return shapeShape;}
	void setCurColor(Color colorChange) {shapeColor = colorChange;}
	void setCurShape(ShapeEnum shapeChange) {shapeShape = shapeChange;}

};
