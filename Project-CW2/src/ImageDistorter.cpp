#include "header.h"
#include "ImageDistorter.h"


ImageDistorter::ImageDistorter(BaseEngine* engine, int x, int y) {

	m_pEngine = engine;
	i_x = x;
	i_y = y;
}


bool ImageDistorter::changePixelColour(int x, int y, int& colour, DrawingSurface* pTarget) { // actually change the colour of a pixel since the original did nothing....

	pTarget->setPixel(x, y, colour);

	return true;
}

bool ImageDistorter::mapCoordinates(double& x, double& y, const SimpleImage& image) {
	


	return true;
}



void  ImageDistorter::setX(int x) { i_x = x; }

void  ImageDistorter::setY(int y) { i_y = y; }