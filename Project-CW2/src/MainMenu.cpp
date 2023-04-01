#include "header.h"
#include "Main_Menu.h"
#include "BaseEngine.h"


void Main_Menu::virtDraw() {

	//std::cout << "VirtDraw" << std::endl;
	//std::cout << "Sprite x " << sprite_X << " | len of placements " << xPlacements.size() << "Placement[" << sprite_X << "]: " << xPlacements.at(sprite_X) << std::endl;
	image.renderImageWithMask(m_pEngine->getForegroundSurface(),xPlacements.at(sprite_X), 300, 620, 60, 100, 160);

}


void Main_Menu::virtDoUpdate(int iCurrentTime) {

	//std::cout << "Virt do update " << std::endl;

	//std::cout << iCurrentTime << std::endl;
	if (iCurrentTime % 64 == 0) { updateX(); }


}


void Main_Menu::updateX() {
	
	sprite_X = (sprite_X > (xPlacements.size() - 2)) ?  0 : sprite_X + 1; // for some reason it needs to be -2 not -1?

}

