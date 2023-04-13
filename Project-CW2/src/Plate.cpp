#include "header.h"
#include "Plate.h"
#include "BaseEngine.h"


Plate::Plate(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path, std::string title) : Image::Image(pEngine, iWidth, iHeight,  useTopLeftFor00, objX, objY, path) {

	m_image = ImageManager::loadImage(path, true);
	m_title = title;
}



void Plate::virtDraw() {

	m_image.renderImageWithMask(m_pEngine->getForegroundSurface(), 0, 0, 0, 0, 800, 800, 0x00FF00);

	// TEXT DRAWING
	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(210, 90, m_title.c_str(), 0x3F2832, m_pEngine->getFont("resources/Fonts/Wizard.otf", 100));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(210, 90, m_title.c_str(), 0xF1F1F1, m_pEngine->getFont("resources/Fonts/Wizard.otf", 101));
	m_pEngine->unlockForegroundForDrawing();


	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(290, 270, "MAIN MENU.", 0x3F2832, m_pEngine->getFont("resources/Fonts/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(290, 350, "LOAD GAME.", 0x3F2832, m_pEngine->getFont("resources/Fonts/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();

	m_pEngine->lockForegroundForDrawing();
	m_pEngine->drawForegroundString(350, 430, "EXIT.", 0x3F2832, m_pEngine->getFont("resources/Fonts/Wizard.otf", 50));
	m_pEngine->unlockForegroundForDrawing();
	// TEXT DRAWING


}
