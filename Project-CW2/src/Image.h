#pragma once

#include "DisplayableObject.h"
#include "ImageManager.h"


class Image : public DisplayableObject{

protected:

	SimpleImage m_image;
	int m_xPos;
	int m_yPos;
	int m_w;
	int m_y;


public:

	Image::Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path);

	virtual void virtDraw() override;

};

