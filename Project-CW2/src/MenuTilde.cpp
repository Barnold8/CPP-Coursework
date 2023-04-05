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
			// This is just here to satisfy the constructor 
}