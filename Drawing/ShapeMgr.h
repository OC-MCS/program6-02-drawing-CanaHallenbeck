#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;


class ShapeMgr
{
private:
	
	int amountFilled = 0;
	vector<DrawingShape*>shapesDrawn;

public:

	ShapeMgr()
	{
		// ?
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			shapesDrawn.push_back(new Circle(pos, color));
			amountFilled++;
		}
		else
		{
			shapesDrawn.push_back(new Square(pos, color));
			amountFilled++;
		}
	}

	const DrawingShape* getList(int i) { return shapesDrawn[i]; };
	int getAmntFilled() { return amountFilled; };

	void readFile(ifstream & in, SettingsMgr * mgr)
	{
		int colorNum = 0;
		Color color = Color::Blue;
		ShapeEnum type = CIRCLE;
		Vector2f loc(0,0);

		ShapeData temp;

		while (in.read(reinterpret_cast<char*>(&temp), sizeof(ShapeData)))
		{
			color = Color(temp.shapeColor);
			loc.x = temp.shapeLocationX;
			loc.y = temp.shapeLocationY;
			type = temp.shapeType;

			addShape(loc, type, color);
		}
		
		mgr->setCurColor(color);
		mgr->setCurShape(type);
	}
	
	void writeFile(ostream & o)
	{
		for (int i = 0; i < amountFilled; i++)
		{
			o.write(reinterpret_cast<char*>(&shapesDrawn[i]->getFileRecord()), 
				    sizeof(shapesDrawn[i]->getFileRecord()));
		}

	}
};


