
#include "header.h"
#include "Image.h"
#include "BaseEngine.h"
#include "Office_Apocalypse.h"


Image::Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path) : DisplayableObject(pEngine, iWidth, iHeight, useTopLeftFor00) {

	m_image = ImageManager::loadImage(path, true);
}

void Image::virtDraw() {

	m_image.renderImageWithMask(m_pEngine->getForegroundSurface(), 0, 0, 0, 0, 800, 800, 0x00FF00);

	
}