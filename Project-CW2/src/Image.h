#pragma once

#include "DisplayableObject.h"
#include "ImageManager.h"


class Image : public DisplayableObject{

private:

	SimpleImage m_image;
	int m_xPos;
	int m_yPos;
	int m_w;
	int m_y;
	std::string m_title;

public:

	Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path);

	Image::Image(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path, std::string title);

	virtual void virtDraw() override;

};

