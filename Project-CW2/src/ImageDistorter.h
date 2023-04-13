#pragma once
#include "ImagePixelMapping.h"
#include "BaseEngine.h"


class ImageDistorter : public ImagePixelMapping{ // class used to give some visual effect to an image. MUST BE AN OBJECT IN THE IMAGE 


private:

	BaseEngine* m_pEngine;
	
	// image x and y
	int i_x;
	int i_y;

public:

	ImageDistorter(BaseEngine* engine, int x, int y); // So i can use engine functionality

	virtual bool mapCoordinates(double& x, double& y, const SimpleImage& image) override;

	virtual bool changePixelColour(int x, int y, int& colour, DrawingSurface* pTarget);

	void setX(int x);

	void setY(int y);

};

