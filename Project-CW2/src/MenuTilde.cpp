#include "header.h"
#include "MenuTilde.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"

void MenuTilde::virtDraw() {
	// make this an underline for what you are selecting

	m_pEngine->drawForegroundRectangle(m_xPos[m_pos_counter]-2, m_yPos[m_pos_counter]-2, m_xPos[m_pos_counter]-2 + m_widths[m_pos_counter]+4, m_yPos[m_pos_counter] + 12, 0x000000);
	m_pEngine->drawForegroundRectangle(m_xPos[m_pos_counter], m_yPos[m_pos_counter], m_xPos[m_pos_counter] + m_widths[m_pos_counter], m_yPos[m_pos_counter] + 10, 0xE4A672);

}

void MenuTilde::virtKeyDown(int iKeyCode) { 



	switch (iKeyCode) { // What is up with these awful keycodes?

	case 1073741906: // UP ARROW
		m_pos_counter--;
		if (m_pos_counter < 0) {
			m_pos_counter = 2;
		}
		break;

	case 1073741905: // DOWN ARROW

		m_pos_counter++;
		if (m_pos_counter > 2) {
			m_pos_counter = 0;
		}
		break;
	default:
		break;
	}


}

MenuTilde::MenuTilde(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
		// Default constructor because I originally only made the tilde for the main menu
		int m_yPos[3] = { 325,395,475 };
		int m_xPos[3] = { 170,170,220 };
		int m_widths[3] = { 180,180,70 };
		std::cout << "FFF" << std::endl;
}


MenuTilde::MenuTilde(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, int xPositions[3], int yPositions[3], int Widths[3]) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
	// Default constructor because I originally only made the tilde for the main menu
	int m_yPos[3] = {yPositions[0],yPositions[1],yPositions[2]};
	int m_xPos[3] = { xPositions[0],xPositions[1],xPositions[2] };
	int m_widths[3] = { Widths[0],Widths[1],Widths[2] };
}