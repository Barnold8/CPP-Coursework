#pragma once
#include "DisplayableObject.h"
#include "ImageManager.h"
#include "vector"

class Main_Menu : public DisplayableObject // To be stored in a GUI state, this is going to handle all of the GUI stuff
{

private:

	SimpleImage image;
	int sprite_X = 0;
	

public:
	std::vector<int> xPlacements = { 20,125,235,340,450,560,673,775,879 };


	Main_Menu(BaseEngine *engine) : DisplayableObject(engine) {
	
		image = ImageManager::loadImage("resources/AdamPhoneSprites.png", true);
		
	}

	// Simple image doesnt want to be here but it worked fine on the cw1. wtf is going on
	virtual void virtDraw() override;

	virtual void virtDoUpdate(int iCurrentTime) override;

	void updateX(); 
};

