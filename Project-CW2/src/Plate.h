#pragma once

#include "Image.h"

class Plate : public Image{

private:

	std::string m_title;

public:
	Plate(BaseEngine* pEngine, int iWidth, int iHeight, bool useTopLeftFor00, int objX, int objY, std::string path, std::string title);

	virtual void virtDraw() override;

};

