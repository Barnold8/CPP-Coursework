#pragma once
#include "ImagePixelMapping.h"
#include "BaseEngine.h"


class ImageDistorter : public ImagePixelMapping{


private:

	BaseEngine* m_pEngine;

public:

	ImageDistorter(BaseEngine* engine); // So i can use engine functionality

	virtual bool mapCoordinates(double& x, double& y, const SimpleImage& image) override;

};

