#include "Shape.h"
#include <iostream>
using namespace std;

Circle::Circle(Vector2f mPos, Color chosenColor) : DrawingShape(mPos, chosenColor, CIRCLE) 
{
	drawnCircle.setPosition(mPos);
	drawnCircle.setRadius(30);
	drawnCircle.setOutlineThickness(2);
	drawnCircle.setOutlineColor(chosenColor);
	drawnCircle.setFillColor(chosenColor);


	SD.shapeColor = chosenColor.toInteger();
	SD.shapeLocationX = mPos.x; 
	SD.shapeLocationY = mPos.y;
	SD.shapeType = CIRCLE;
};

void Circle::draw(RenderWindow & win) const
{
	win.draw(drawnCircle);
}

ShapeData Circle::getFileRecord() const
{
	return SD;
}

Square::Square(Vector2f mPos, Color chosenColor) : DrawingShape(mPos, chosenColor, SQUARE)
{
	drawnRectangle.setPosition(mPos);
	drawnRectangle.setOutlineThickness(2);
	drawnRectangle.setSize(Vector2f(40, 40));
	drawnRectangle.setOutlineColor(chosenColor);
	drawnRectangle.setFillColor(chosenColor);

	SD.shapeColor = chosenColor.toInteger();
	SD.shapeLocationX = mPos.x;
	SD.shapeLocationY = mPos.y;
	SD.shapeType = SQUARE;
};

void Square::draw(RenderWindow & win) const
{
	win.draw(drawnRectangle);
}

ShapeData Square::getFileRecord() const
{
	return SD;
}
