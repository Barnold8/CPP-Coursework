#include "header.h"
#include "ImageDistorter.h"


ImageDistorter::ImageDistorter(BaseEngine* engine) {

	m_pEngine = engine;
}

bool ImageDistorter::mapCoordinates(double& x, double& y, const SimpleImage& image) {

	int iOffset = m_pEngine->getModifiedTime() / 10;

	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (image.getWidth() - 0.5)) return false;
	if (y >= (image.getHeight() - 0.5)) return false;

	 //Demo 1 - shift x
	//x = ((int)(x + 0.5) + iOffset) % image.getWidth();

	// Demo 2 - shift y
//	y = ((int)(y + 0.5) + iOffset) % image.getHeight();

	// Demo 3 - simple rotation

	// Shift offset to the centre of the image, so we can rotate around centre
	x -= image.getWidth() / 2;
	y -= image.getHeight() / 2;

	// Rotate it
	//double dAngle = (double)iOffset / 100;
	double dAngle = atan(y / (x + 0.0001));
	if (x < 0)
		dAngle += M_PI;
	double hyp = ::sqrt(x * x + y * y);
	dAngle += (double)iOffset / 100;

	x = hyp * ::cos(dAngle);
	y = hyp * ::sin(dAngle);

	// Shift offset back to the corner
	x += image.getWidth() / 2;
	y += image.getHeight() / 2;

	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (image.getWidth() - 0.5)) return false;
	if (y >= (image.getHeight() - 0.5)) return false;

	return true;
}
