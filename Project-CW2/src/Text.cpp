#include "header.h"
#include "Text.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"


Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_text = "Placeholder";
	m_editable = false;
	m_x = 10;
	m_y = 10;
	m_s = 10;
	m_cap = 10;

}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
	m_text = text;
	m_editable = false;
	m_x = 10;
	m_y = 10;
	m_s = 10;
	m_cap = 10;
}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, bool editable) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
	m_text = text;
	m_editable = editable;
	m_x = 10;
	m_y = 10;
	m_s = 10;
	m_cap = 10;
}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
	m_text = text;
	m_editable = false;
	m_x = x;
	m_y = y;
	m_s = 10;
	m_cap = 10;
}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_text = text;
	m_editable = false;
	m_x = x;
	m_y = y;
	m_s = s;
	m_cap = 10;
}
Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, bool editable) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_text = text;
	m_editable = editable;
	m_x = x;
	m_y = y;
	m_s = s;
	m_cap = 10;
}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, int CAP) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {
	m_text = text;
	m_editable = false;
	m_x = x;
	m_y = y;
	m_s = s;
	m_cap = CAP;

}

Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, bool editable) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_text = text;
	m_editable = editable;
	m_x = x;
	m_y = y;
	m_s = 10;
	m_cap = 10;
}


Text::Text(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string text, int x, int y, int s, int CAP, bool editable) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_text = text;
	m_editable = editable;
	m_x = x;
	m_y = y;
	m_s = s;
	m_cap = CAP;
}



void Text::virtDraw() {

	//M->drawBackgroundString(215, 390, "Exit.", 0x3F2832, M->getFont("resources/Wizard.otf", 50));
	m_pEngine->drawForegroundString(m_x, m_y, m_text.c_str(), 0x000000, m_pEngine->getFont("resources/Fonts/Minecraft.ttf", m_s));

}

void Text::virtKeyDown(int iKeyCode) {

	if (m_editable) { // controls the text if i can be edited by user input or not
		if (iKeyCode == 8 && m_text.length() - 1 > 0) {
			std::cout << "Len " << m_text.length() << std::endl;
			m_text.erase(m_text.length() - 1, 1);
		}
		else if (iKeyCode > 96 && iKeyCode < 123 && m_text.length() < m_cap) {
			m_text += iKeyCode - 32;
		}

		if (m_text.size() > 1) {
		
			Text* annoyance = dynamic_cast<Text*>(m_pEngine->getDisplayableObject(1));

			m_pEngine->removeDisplayableObject(annoyance);
			delete annoyance;
		}
	}

}

bool Text::setText(std::string text) { 

	if (text.length() > m_cap) {
		return false;
	}
	
	m_text = text;
	return true;
}

std::string Text::getText() { return m_text; }