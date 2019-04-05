#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

//-----------------------------------------------------
//	Shape Manager -- List of 'drawing shapes' (vec)
//----------------------------------------------------


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

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color);
	const DrawingShape* getList(int i) { return shapesDrawn[i]; };
	int getAmntFilled() { return amountFilled; };
	void readFile(ifstream & in, SettingsMgr * mgr);
	void writeFile(ostream & o);

};


