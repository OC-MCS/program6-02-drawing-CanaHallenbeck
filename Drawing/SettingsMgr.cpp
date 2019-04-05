#include "SettingsMgr.h"

//-----------------------------------------------------
//	Settings Manager -- maintains current settings 
//  (current color, shape)
//----------------------------------------------------

SettingsMgr::SettingsMgr(Color startingColor, ShapeEnum startingShape)
{
	shapeColor = startingColor;
	shapeShape = startingShape;
}
