
#include "header.h"
#include "Image.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"


Image::Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {


}


Image::Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY,std::string path) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {


	m_image = ImageManager::loadImage(path, true);

}

void Image::virtDraw() {

	m_image.renderImageWithMask(m_pEngine->getForegroundSurface(), 0, 0, 0, 0, 800, 800, 0x00FF00);

	// TEXT DRAWING
	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(210, 90, "YOU LOSE!", 0x3F2832, m_pEngine->getFont("resources/Wizard.otf", 100));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(210, 90, "YOU LOSE!", 0xF1F1F1, m_pEngine->getFont("resources/Wizard.otf", 101));
	m_pEngine->unlockForegroundForDrawing();


	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(290, 270, "MAIN MENU.", 0x3F2832, m_pEngine->getFont("resources/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(290, 350, "LOAD GAME.", 0x3F2832, m_pEngine->getFont("resources/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(350, 430, "EXIT.", 0x3F2832, m_pEngine->getFont("resources/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();
	// TEXT DRAWING


}