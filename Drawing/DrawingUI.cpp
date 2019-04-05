#include "DrawingUI.h"
using namespace std;

//-----------------------------------------------------
//	Drawing UI -- 
//	Responsible for user interface; drawing 
//	shapes on screen; tells shapeMgr location of shapes
//----------------------------------------------------

DrawingUI::DrawingUI(Vector2f p)
{

	canvas.setPosition(p);
	canvas.setOutlineColor(Color::White);
	canvas.setOutlineThickness(3);
	canvas.setSize(Vector2f(610, 600));
	canvas.setFillColor(Color::Transparent);

}

void DrawingUI::draw(RenderWindow & win, ShapeMgr * mgr)
{
	win.draw(canvas);

	for (int i = 0; mgr->getAmntFilled() > 0 && i < mgr->getAmntFilled(); i++)
	{
		mgr->getList(i)->draw(win);
	}
}

bool DrawingUI::isMouseInCanvas(Vector2f mousePos)
{
	if (canvas.getGlobalBounds().contains(mousePos) && mousePos.x < 760 && mousePos.y < 590)
		return true;
	else
		return false;
}
