#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	Color shapeColor;
	ShapeEnum shapeShape;
public:

	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		shapeColor = startingColor;
		shapeShape = startingShape;
	}

	Color getCurColor() {return shapeColor;}
	ShapeEnum getCurShape() {return shapeShape;}
	void setCurColor(Color colorChange) {shapeColor = colorChange;}
	void setCurShape(ShapeEnum shapeChange) {shapeShape = shapeChange;}

};
