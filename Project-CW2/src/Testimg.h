#pragma once
#include "DisplayableObject.h"

class Testimg : public DisplayableObject
{

private:

	SimpleImage image;


public:

	Testimg(BaseEngine* pEngine) : DisplayableObject(pEngine) {
		SimpleImage image = ImageManager::loadImage("resources/Background.png", true);
	}

	//Testimg(BaseEngine* pEngine,std::string path) : DisplayableObject(pEngine) {
	//	SimpleImage image = ImageManager::loadImage(path, true);
	//}

	//int s_x;
	//int s_y;
	//int s_w;
	//int s_h;
	


	virtual void virtDraw() override;

	virtual void virtDoUpdate(int iCurrentTime) override;

	
};

