#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "SettingsMgr.h"
using namespace std;
using namespace sf;


//-----------------------------------------------------
//	Shape -- 
//
//	* ShapeData = struct for writing to a binary file
//  * DrawingShape = abstract base class for circles
//    and squares;
//----------------------------------------------------


struct ShapeData
{
	ShapeEnum shapeType;
	int shapeLocationX,
		shapeLocationY,
		shapeColor;
};

class DrawingShape
{
private:
	Vector2f shapeLoc;
	Color shapeColor;
	ShapeEnum shape;
	ShapeData SD; // <------------------------- "Shape Data"; struct holding the information to write to / read from binary file
public:
	DrawingShape(Vector2f l, Color c, ShapeEnum type);
	virtual void draw(RenderWindow & win) const = 0;
	virtual ShapeData getFileRecord() const = 0;

}; //  <<------------,						              ,-----------------,. 
   //            	 |					 	            /'    *  RIP  *	     \\												
   //				  `------------------------------  |   Nearly a week of   ||
   //									               |    Cana's life was   ||    so,           
   //								                   |	 wasted here;	  ||        so			    
   //    						               so      |  let us never forget ||   dumb      				`
   //						  		        '     sad  |  the tragedy of the  ||         		   `							    '
   //							  `	    `             ,|   missing bracket    ||       `     O   #		~	,		'						'
   //	                #   O   #   *    ,.     '      | ,   ,	_	.,	_	,'||, ~	`  ,  , \|/ \|/ ,				       w	   `
   //    _  ,~ . ,_ .  \|/ \|/ \|/_\|/ . _ y _ V ,,. '_;,**#@*#.*-;,*#*_y__*#@*v#*"._*\Vv\/,_vVv~',.`'~  - ,   ~  _` |/, \ | / . .    `  _   -  _   .
   //	`	 '	`	  ~	 - `  -          `	'	`"'	'	`"'	,'	'	~ ``	 '	`	   `	,		-		`			
   //								  `				-						`							`	 

class Circle : public DrawingShape
{
private:
	CircleShape drawnCircle;
	ShapeData SD;
public:
	Circle(Vector2f mPos, Color chosenColor);
    
	void draw(RenderWindow & win) const;
	ShapeData getFileRecord() const;
};

class Square : public DrawingShape
{
private:
	RectangleShape drawnRectangle;
	ShapeData SD;
public:
	Square(Vector2f mPos, Color chosenColor);
	
	void draw(RenderWindow & win) const;
	ShapeData getFileRecord() const;
};

