#pragma once

#include "DisplayableObject.h"

// the object that is rendered like a menu selector. 
class MenuTilde : public DisplayableObject{

private:
	int m_yPos[3];
	int m_xPos[3];
	int m_widths[3];
	int m_pos_counter = 0;
public:
	//DisplayableObject(BaseEngine* pEngine, int iWidth = 0, int iHeight = 0, bool useTopLeftFor00 = true);
	MenuTilde(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY);

	MenuTilde(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, int xPositions[3],int yPositions[3], int Widths[3]);

	~MenuTilde() { std::cout << "Menu deleted" << std::endl; }

    virtual void virtDraw() override;

	virtual void virtKeyDown(int iKeyCode) override;

};

